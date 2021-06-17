#include "Arraylist.h"

void Arraylist::onRender() {
	auto player = gData.getClientInstance()->LocalPlayer();

	if (player == nullptr || !gData.getClientInstance()->MinecraftGame()->canUseKeys())
		return;

	auto res = gData.getClientInstance()->getGuiData()->scaledRes;
	auto y = 5;

	std::vector<class Module*> modules;

	for (int i = 0; i < moduleMgr.modules.size(); i++) {
		auto mod = moduleMgr.modules.at(i);

		if (mod->isEnabled)
			modules.push_back(mod);
	}

	for (int i = 0; i < modules.size(); i++) {
		auto mod = modules.at(i);

		auto pos = Vec2(res.x - RenderUtils::getTextWidth(mod->name, 1) - 2, y);
		auto boxPos = Vec4(pos.x - 2, y, res.x, y + 12);

		RenderUtils::renderText(mod->name, pos, Color(255, 255, 255), 1, 1);
		RenderUtils::fillRectangle(boxPos, Color(211, 211, 211), .2f);

		float lineWidth = .5f;

		/*
		if (i == 0) {
			float minN = min(RenderUtils::getTextWidth(mod->name, 1), RenderUtils::getTextWidth(modules.at(i + 1)->name, 1));
			float maxN = max(RenderUtils::getTextWidth(mod->name, 1), RenderUtils::getTextWidth(modules.at(i + 1)->name, 1));
			float width = maxN - minN;

			RenderUtils::fillRectangle(Vec4(boxPos.x - lineWidth, boxPos.y - lineWidth, boxPos.z + lineWidth, boxPos.y + lineWidth), Color(255, 255, 255), 1.f);
			RenderUtils::fillRectangle(Vec4(boxPos.x - lineWidth, boxPos.w - lineWidth, boxPos.z - lineWidth - width * 2 + 1, boxPos.w + lineWidth), Color(255, 255, 255), 1.f);
		}
		else if (i == modules.size() - 1) {
			float minN = min(RenderUtils::getTextWidth(mod->name, 1), RenderUtils::getTextWidth(modules.at(i - 1)->name, 1));
			float maxN = max(RenderUtils::getTextWidth(mod->name, 1), RenderUtils::getTextWidth(modules.at(i - 1)->name, 1));
			float width = abs(maxN - minN);

			RenderUtils::fillRectangle(Vec4(boxPos.x - lineWidth, boxPos.y - lineWidth, boxPos.z - lineWidth - width * 2 + 1, boxPos.y + lineWidth), Color(255, 255, 255), 1.f);
			RenderUtils::fillRectangle(Vec4(boxPos.x - lineWidth, boxPos.w - lineWidth, boxPos.z + lineWidth, boxPos.w + lineWidth), Color(255, 255, 255), 1.f);
		}
		*/

		RenderUtils::fillRectangle(Vec4(boxPos.x - lineWidth, boxPos.y, boxPos.x + lineWidth, boxPos.w), Color(255, 255, 255), 1.f);


		y += 12;
	}
}
