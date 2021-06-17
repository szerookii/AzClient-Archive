#include "TabGUI.h"

void TabGUI::onRender() {
	RenderUtils::renderText("AzClient", Vec2(5, 5), Color(255, 255, 255), 1.0f, 1.0f);

	if (gData.getClientInstance() != nullptr && gData.getClientInstance()->MinecraftGame()->canUseKeys()) {
		auto categories = moduleMgr.categories;
		auto modules = moduleMgr.getModulesFromCategory(categories.at(currentCategory));
		float boxWidth = RenderUtils::getTextWidth(SortArrayOfStrings(categories).back(), 1.0f);
		Vec4 boxPos = Vec4(20, 20, boxWidth + 40, categories.size() * 10 + 30);

		Color whiteText = Color(255, 255, 255), selectedColourText = Color(0, 255, 0);

		for (int C = 0; C < categories.size(); C++) {
			RenderUtils::renderText(">", Vec2(boxPos.z - 10, currentCategory * 10 + 30), selectedColourText, 1.0f, selectedCategory ? 1.0f : 0.f);
			RenderUtils::renderText(categories.at(C), Vec2(boxPos.x + 2, C * 10 + 30), selectedCategory && currentCategory == C ? selectedColourText : whiteText, 1.0f, 1.0f);
		}
		if (selectedModule) {
			std::vector< std::string> modulesText;

			for (auto Mod : modules) {
				modulesText.push_back(Mod->name);
			}

			float modulesWidth = RenderUtils::getTextWidth(SortArrayOfStrings(modulesText).back(), 1.0f);
			Vec4 modulesPos = Vec4(boxWidth + 40, 20, boxWidth + modulesWidth + 55, modules.size() * 10 + 30);
			RenderUtils::renderText(categories.at(currentCategory), Vec2(modulesPos.x + 2, 20), Color(0, 255, 0), 1.0f, 1.0f);

			for (int M = 0; M < modules.size(); M++) {
				RenderUtils::renderText(">", Vec2(modulesPos.z - 10, currentModule * 10 + 30), selectedColourText, 1.0f, selectedModule ? 1.0f : 0.f);
				RenderUtils::renderText(modules.at(M)->name, Vec2(modulesPos.x + 2, M * 10 + 30), selectedModule && modules.at(M)->isEnabled ? selectedColourText : whiteText, 1.0f, 1.0f);
			}

			RenderUtils::fillRectangle(modulesPos, Color(90, 90, 90), .5f);
			RenderUtils::drawRectangle(modulesPos, Color(255, 255, 255), .5f, .8f);
		}

		RenderUtils::fillRectangle(boxPos, Color(90, 90, 90), .5f);
		RenderUtils::drawRectangle(boxPos, Color(255, 255, 255), .5f, .8f);
		RenderUtils::flushText();
	}
}

void TabGUI::onKey(uint64_t key, bool isDown, bool* cancel) {
	auto categories = moduleMgr.categories;
	auto modules = moduleMgr.getModulesFromCategory(categories.at(currentCategory));

	if (isDown && gData.getClientInstance() != nullptr && gData.getClientInstance()->MinecraftGame()->canUseKeys()) {
		if (key == 0x25) { //Left
			if (selectedModule) {
				currentModule = 0;
				selectedModule = false;
			}
			else {
				if (selectedCategory) {
					selectedCategory = false;
				}
			}

			*cancel = true;
		}

		if (key == 0x27) { //Right
			if (!selectedCategory) {
				selectedCategory = true;
			}
			else {
				if (!selectedModule) {
					selectedModule = true;
				}
				else {
					Module* currModule = modules.at(currentModule);

					if (currModule != nullptr)
						currModule->isEnabled = !currModule->isEnabled;
				}
			}

			*cancel = true;
		}

		if (key == 0x26) { //Up
			if (selectedCategory && !selectedModule) {
				if (!currentCategory)
					currentCategory = categories.size();

				currentCategory--;
			}
			else {
				if (selectedModule) {
					if (!currentModule)
						currentModule = modules.size();

					currentModule--;
				}
			}

			*cancel = true;
		}

		if (key == 0x28) { //Down
			if (selectedCategory && !selectedModule) {
				currentCategory++;

				if (currentCategory >= categories.size())
					currentCategory = 0;
			}
			else {
				if (selectedModule) {
					currentModule++;

					if (currentModule >= modules.size())
						currentModule = 0;
				}
			}

			*cancel = true;
		}
	}
}