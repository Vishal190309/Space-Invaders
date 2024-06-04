#include "../../Header/Player/PlayerModel.h"

namespace Player {

	int PlayerModel::playerLives;
	int PlayerModel::enemiesKilled;
	PlayerModel::PlayerModel(Entity::EntityType entityType)
	{ 
		this->entityType = entityType;
	}

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); } // remember to call reset() 

	void PlayerModel::reset()
	{
		playerState = PlayerState::ALIVE; // set state to alive
		playerPosition = initialPlayerPosition;

		playerLives = maxPlayerLives;
		enemiesKilled = 0;

		bShield = false;
		bTrippleLaser = false;
		bRapidFire = false;
		
	}


	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return playerPosition;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		playerPosition = position;
	}

	int PlayerModel::getPlayerScore()
	{
		return playerScore;
	}

	void PlayerModel::setPlayerScore(int score)
	{
		playerScore = score;
	}

	//..
	PlayerState PlayerModel::getPlayerState()
	{
		return playerState;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		playerState = state;
	}
	

	Entity::EntityType PlayerModel::getEntityType()
	{
		return entityType;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return bShield;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return bRapidFire;
	}

	bool PlayerModel::isTrippleLaserEnabled()
	{
		return bTrippleLaser;
	}

	void PlayerModel::setShieldState(bool value)
	{
		bShield = value;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		bRapidFire = value;
	}

	void PlayerModel::setTrippleLaserState(bool value)
	{
		bTrippleLaser = value;
	}
	
}