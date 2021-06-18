#pragma once

#include "../utils/Utils.h"
#include "MultiPlayerLevel.h"
#include "ItemStack.h"

class Actor {
public:
	char pad_0008[312]; //0x0008
	Vec2 bodyRot; //0x0140
	char pad_0148[152]; //0x0148
	bool onGround; //0x01E0
	char pad_01E1[95]; //0x01E1
	float stepHeight; //0x0240
	char pad_0244[652]; //0x0244
	Vec3 position; //0x04D0
	char pad_04DC[60]; //0x04DC
	Vec3 velocity; //0x0518
	char pad_0524[888]; //0x0524

	virtual bool hasComponent(class HashedString* param_1);
	virtual void reloadHardcoded(class InitializationMethod* param_1, class VariantParameterList* param_2);
	virtual void reloadHardcodedClient(class InitializationMethod* param_1, class VariantParameterList* param_2);
	virtual void initializeComponents(class InitializationMethod* param_1, class VariantParameterList* param_2);
	virtual void reloadComponents(class InitializationMethod* param_1, class VariantParameterList* param_2);
	virtual void _serverInitItemStackIds();
	virtual void _doInitialMove();
	virtual void* UndefinedFunc_7(void* param_1);
	virtual void reset();
	virtual int getOnDeathExperience();
	virtual class ActorType* getOwnerEntityType();
	virtual void remove();
	virtual void setPos(struct Vec3* param_1);
	virtual __int64 __vcrt_uninitialize0();
	virtual class PredictedMovementValues* getPredictedMovementValues();
	virtual struct Vec3* getPos();
	virtual struct Vec3* getPosOld();
	virtual struct Vec3* getPosExtrapolated(float param_1);
	virtual struct Vec3* getAttachPos(class ActorLocation* param_1, float param_2);
	virtual struct Vec3* getFiringPos();
	virtual void setRot(struct Vec2* param_1);
	virtual void move(class IActorMovementProxy* param_1, struct Vec3* param_2);
	virtual void move(struct Vec3* param_1);
	virtual struct Vec3* getInterpolatedRidingPosition(float param_1);
	virtual float getInterpolatedBodyRot(float param_1);
	virtual float getInterpolatedHeadRot(float param_1);
	virtual float getInterpolatedBodyYaw(float param_1);
	virtual float getYawSpeedInDegreesPerSecond();
	virtual float getInterpolatedWalkAnimSpeed(float param_1);
	virtual struct Vec3* getWorldPosition();
	virtual void checkBlockCollisions(class AABB* param_1, class std::function<void __cdecl(class BlockSource const&, class Block const&, class BlockPos const&, class Actor&)>* param_2);
	virtual void updateEntityInside();
	virtual void updateEntityInside(class AABB* param_1);
	virtual bool isFireImmune();
	virtual __int64 getReturnPolicy0();
	virtual void blockedByShield(class ActorDamageSource* param_1, class Actor* param_2);
	virtual void teleportTo(struct Vec3* param_1, bool param_2, int param_3, int param_4);
	virtual bool tryTeleportTo(struct Vec3* param_1, bool param_2, bool param_3, int param_4, int param_5);
	virtual void chorusFruitTeleport(struct Vec3* param_1);
	virtual void lerpTo(struct Vec3* param_1, struct Vec2* param_2, int param_3);
	virtual void lerpMotion(struct Vec3* param_1);
	virtual class AddActorBasePacket* tryCreateAddActorPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider(class Actor* param_1, float param_2);
	virtual float getRidingHeight();
	virtual bool startRiding(class Actor* param_1);
	virtual void addRider(class Actor* param_1);
	virtual void flagRiderToRemove(class Actor* param_1);
	virtual std::string* getExitTip(std::string* param_1, class InputMode* param_2);
	virtual bool intersects(struct Vec3* param_1, struct Vec3* param_2);
	virtual bool isFree(struct Vec3* param_1);
	virtual bool isFree(struct Vec3* param_1, float param_2);
	virtual bool isInWall();
	virtual bool isInvisible();
	virtual bool canShowNameTag();
	virtual __int64 __vcrt_uninitialize1();
	virtual void setNameTagVisible(bool param_1);
	virtual std::string* getNameTag();
	virtual __int64 JS_GetContextOpaque();
	virtual std::string* getFormattedNameTag();
	virtual void filterFormattedNameTag(class UIProfanityContext* param_1);
	virtual void setNameTag(std::string* param_1);
	virtual __int64 getReturnPolicy1();
	virtual void setScoreTag(std::string* param_1);
	virtual std::string* getScoreTag();
	virtual bool isInWater();
	virtual bool hasEnteredWater();
	virtual bool isImmersedInWater();
	virtual bool isInLava();
	virtual bool isUnderLiquid(class MaterialType* param_1);
	virtual bool isOverWater();
	virtual void setBlockMovementSlowdownMultiplier(struct Vec3* param_1);
	virtual void resetBlockMovementSlowdownMultiplier();
	virtual __int64 stbir__support_zero0();
	virtual float getShadowHeightOffs();
	virtual float getShadowRadius();
	virtual struct Vec3* getHeadLookVector(float param_1);
	virtual __int64 getReturnPolicy2();
	virtual bool canSee(struct Vec3* param_1);
	virtual bool canSee(class Actor* param_1);
	virtual bool isSkyLit(float param_1);
	virtual float getBrightness(float param_1);
	virtual __int64 getReturnPolicy3();
	virtual __int64 _guard_check_icall0();
	virtual void onAboveBubbleColumn(bool param_1);
	virtual void onInsideBubbleColumn(bool param_1);
	virtual bool isImmobile();
	virtual bool isSilent();
	virtual bool isPickable();
	virtual __int64 __vcrt_uninitialize2();
	virtual bool isSleeping();
	virtual __int64 __vcrt_uninitialize3();
	virtual void setSneaking(bool param_1);
	virtual bool isBlocking();
	virtual __int64 getReturnPolicy4();
	virtual bool isAlive();
	virtual bool isOnFire();
	virtual bool isOnHotBlock();
	virtual __int64 getReturnPolicy5();
	virtual bool isSurfaceMob();
	virtual __int64 __vcrt_uninitialize4();
	virtual __int64 getReturnPolicy6();
	virtual __int64 getReturnPolicy7();
	virtual bool isAffectedByWaterBottle();
	virtual bool canAttack(class Actor* param_1, bool param_2);
	virtual void setTarget(class Actor* param_1);
	virtual int UndefinedFunc_108();
	virtual __int64 __vcrt_uninitialize5();
	virtual bool attack(class Actor* param_1);
	virtual void performRangedAttack(class Actor* param_1, float param_2);
	virtual __int64 _guard_check_icall1();
	virtual int getEquipmentCount();
	virtual void setOwner(class ActorUniqueID* param_1);
	virtual void setSitting(bool param_1);
	virtual __int64 _guard_check_icall2();
	virtual __int64 _guard_check_icall3();
	virtual int getInventorySize();
	virtual int getEquipSlots();
	virtual int getChestSlots();
	virtual void setStanding(bool param_1);
	virtual bool canPowerJump();
	virtual void setCanPowerJump(bool param_1);
	virtual bool isJumping();
	virtual bool isEnchanted();
	virtual __int64 _guard_check_icall4();
	virtual __int64 _guard_check_icall5();
	virtual bool shouldRender();
	virtual bool isInvulnerableTo(class ActorDamageSource* param_1);
	virtual class ActorDamageCause* getBlockDamageCause(class Block* param_1);
	virtual void actuallyHurt(int param_1, class ActorDamageSource* param_2, bool param_3);
	virtual void animateHurt();
	virtual bool doFireHurt(int param_1);
	virtual void onLightningHit();
	virtual __int64 _guard_check_icall6();
	virtual void feed(int param_1);
	virtual void handleEntityEvent(class ActorEvent* param_1, int param_2);
	virtual float getPickRadius();
	virtual class HashedString* getActorRendererId();
	virtual class ItemActor* spawnAtLocation(class ItemStack* param_1, float param_2);
	virtual class ItemActor* spawnAtLocation(class Block* param_1, int param_2, float param_3);
	virtual class ItemActor* spawnAtLocation(class Block* param_1, int param_2);
	virtual class ItemActor* spawnAtLocation(int param_1, int param_2, float param_3);
	virtual class ItemActor* spawnAtLocation(int param_1, int param_2);
	virtual void despawn();
	virtual void killed(class Actor* param_1);
	virtual __int64 _guard_check_icall7();
	virtual void setArmor(class ArmorSlot* param_1, class ItemStack* param_2);
	virtual class ItemStack* getArmor(class ArmorSlot* param_1);
	virtual class ArmorMaterialType* getArmorMaterialTypeInSlot(class ArmorSlot* param_1);
	virtual class ArmorTextureType* getArmorMaterialTextureTypeInSlot(class ArmorSlot* param_1);
	virtual float getArmorColorInSlot(class ArmorSlot* param_1, int param_2);
	virtual class ItemStack* getEquippedSlot(class EquipmentSlot* param_1);
	virtual void setEquippedSlot(class EquipmentSlot* param_1, class ItemStack* param_2);
	virtual class ItemStack* getCarriedItem();
	virtual void setCarriedItem(class ItemStack* param_1);
	virtual void setOffhandSlot(class ItemStack* param_1);
	virtual class ItemStack* getEquippedTotem();
	virtual bool consumeTotem();
	virtual bool save(class CompoundTag* param_1);
	virtual void saveWithoutId(class CompoundTag* param_1);
	virtual bool load(class CompoundTag* param_1, class DataLoadHelper* param_2);
	virtual void loadLinks(class CompoundTag* param_1, class std::vector<class ActorLink*> param_2, class DataLoadHelper* param_3);
	virtual class ActorType* getEntityTypeId();
	virtual class HashedString* queryEntityRenderer();
	virtual class ActorUniqueID* getDamagingEntityUniqueID0();
	virtual void setOnFire(int param_1);
	virtual void extinguishFire();
	virtual void thawFreezeEffect();
	virtual bool canFreeze();
	virtual bool isWearingLeatherArmor();
	virtual class AABB* getHandleWaterAABB();
	virtual void handleInsidePortal(class BlockPos* param_1);
	virtual int getPortalCooldown();
	virtual int UndefinedFunc_175();
	virtual __int64* getDimensionId();
	virtual __int64 __vcrt_uninitialize6();
	virtual __int64 _guard_check_icall8();
	virtual void changeDimension(__int64* param_1, bool param_2);
	virtual class ActorUniqueID* getDamagingEntityUniqueID1();
	virtual void checkFallDamage(float param_1, bool param_2);
	virtual void causeFallDamage(float param_1, float param_2, class ActorDamageSource* param_3);
	virtual void handleFallDistanceOnServer(float param_1, float param_2, bool param_3);
	virtual void playSynchronizedSound(class LevelSoundEvent* param_1, struct Vec3* param_2, int param_3, bool param_4);
	virtual void playSynchronizedSound(class LevelSoundEvent* param_1, struct Vec3* param_2, class Block* param_3, bool param_4);
	virtual void onSynchedDataUpdate(int param_1);
	virtual bool canAddRider(class Actor* param_1);
	virtual __int64 __vcrt_uninitialize7();
	virtual __int64 __vcrt_uninitialize8();
	virtual bool inCaravan();
	virtual __int64 getReturnPolicy8();
	virtual void tickLeash();
	virtual void sendMotionPacketIfNeeded();
	virtual __int64 __vcrt_uninitialize9();
	virtual void stopRiding(bool param_1, bool param_2, bool param_3);
	virtual void startSwimming();
	virtual void stopSwimming();
	virtual void buildDebugInfo(std::string* param_1);
	virtual class CommandPermissionLevel* getCommandPermissionLevel();
	virtual class AttributeInstance* getMutableAttribute(class Attribute* param_1);
	virtual class AttributeInstance* getAttribute(class Attribute* param_1);
	virtual int getDeathTime();
	virtual void heal(int param_1);
	virtual bool isInvertedHealAndHarm();
	virtual bool canBeAffected(class MobEffectInstance* param_1);
	virtual bool canBeAffected(int param_1);
	virtual bool canBeAffectedByArrow(class MobEffectInstance* param_1);
	virtual void onEffectAdded(class MobEffectInstance* param_1);
	virtual void onEffectUpdated(class MobEffectInstance* param_1);
	virtual void onEffectRemoved(class MobEffectInstance* param_1);
	virtual class AnimationComponent* getAnimationComponent();
	virtual void openContainerComponent(class Player* param_1);
	virtual void swing();
	virtual void useItem(class ItemStackBase* param_1, class ItemUseMethod* param_2, bool param_3);
	virtual __int64 getReturnPolicy9();
	virtual int UndefinedFunc_216();
	virtual void getDebugText(std::vector<std::string, std::string>* param_1);
	virtual float calcGroundFriction(class Mob* param_1, class BlockPos* param_2);
	virtual float getRiderYRotation(class Actor* param_1);
	virtual float getYHeadRot();
	virtual __int64 getReturnPolicy10();
	virtual __int64 getReturnPolicy11();
	virtual __int64 getReturnPolicy12();
	virtual bool add(class ItemStack* param_1);
	virtual bool drop(class ItemStack* param_1, bool param_2);
	virtual bool getInteraction(class Player* param_1, class ActorInteraction* param_2, struct Vec3* param_3);
	virtual __int64 __vcrt_uninitialize10();
	virtual __int64 _guard_check_icall9();
	virtual void setSize(float param_1, float param_2);
	virtual int getLifeSpan();
	virtual void onOrphan();
	virtual void wobble();
	virtual bool wasHurt();
	virtual void startSpinAttack();
	virtual __int64 _guard_check_icall10();
	virtual void setDamageNearbyMobs(bool param_1);
	virtual __int64 _guard_check_icall11();
	virtual void reloadLootTable(class EquipmentTableDefinition* param_1);
	virtual void reloadLootTable();
	virtual class LootTable* getLootTable();
	virtual int UndefinedFunc_241();
	virtual __int64 stbir__support_zero1();
	virtual void kill();
	virtual void die(class ActorDamageSource* param_1);
	virtual bool shouldTick();
	virtual class IActorMovementProxy* createMovementProxy();
	virtual class IActorMovementProxy* getMovementProxy();
	virtual float getNextStep(float param_1);
	virtual void updateEntitySpecificMolangVariables(class RenderParams* param_1);
	virtual bool shouldTryMakeStepSound();
	virtual __int64 __vcrt_uninitialize11();
	virtual void outOfWorld();
	virtual bool _hurt(class ActorDamageSource* param_1, int param_2, bool param_3, bool param_4);
	virtual void markHurt();
	virtual class AnimationComponent* _getAnimationComponent(class AnimationComponent* param_1, class AnimationComponentGroup* param_2);
	virtual void readAdditionalSaveData(class CompoundTag* param_1, class DataLoadHelper* param_2);
	virtual void addAdditionalSaveData(class CompoundTag* param_1);
	virtual void _playStepSound(class BlockPos* param_1, class Block* param_2);
	virtual void _playFlySound(class BlockPos* param_1, class Block* param_2);
	virtual __int64 getReturnPolicy13();
	virtual void checkInsideBlocks(float param_1);
	virtual void pushOutOfBlocks(struct Vec3* param_1);
	virtual bool updateWaterState();
	virtual void doWaterSplashEffect();
	virtual void spawnTrailBubbles();
	virtual void updateInsideBlock();
	virtual void _removeRider(class ActorUniqueID* param_1, bool param_2, bool param_3, bool param_4);
	virtual void _onSizeUpdated();
	virtual __int64 _guard_check_icall12();
	virtual void knockback(class Actor* param_1, int param_2, float param_3, float param_4, float param_5, float param_6, float param_7);

	inline void look(Vec3* target) {
		auto var4 = target->x - this->getPos()->x;
		auto var8 = target->z - this->getPos()->z;
		auto var6 = target->y - this->getPos()->y;

		auto var14 = sqrt(var4 * var4 + var8 * var8);
		auto var12 = (float)atan2(var8, var4) * 180.f / M_PI - 90.f;
		auto var13 = (float)(-(atan2(var6, var14) * 180.f / M_PI));

		this->bodyRot.x = var13;
		this->bodyRot.y = var12;
	}

	inline class MultiPlayerLevel* getMultiPlayerLevel() {
		if (this != nullptr) {
			return *reinterpret_cast<class MultiPlayerLevel**>(reinterpret_cast<__int64>(this) + 0x378);
		}
		else {
			return nullptr;
		}
	}
};