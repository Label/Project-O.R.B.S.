//=============================================================================
/**
  @file   Unvierse.cpp
  @brief  contains the function definitions of the class WorldGenerator
  @author mwilhelm
  @date   2013-11-27
**/
//=============================================================================
// INCLUDES
//=============================================================================
#include "stdafx.h"

//=============================================================================
// STATIC MEMBER DEFINITIONS
//=============================================================================
WorldGenerator* WorldGenerator::instance_ = 0;

//=============================================================================
// (DE)CONSTRUCTORS
//=============================================================================
/**
  @fn     WorldGenerator::WorldGenerator()
  @brief  default constructor
**/
//=============================================================================
WorldGenerator::WorldGenerator()
{
  LOG_DEBUG("entered: WorldGenerator::WorldGenerator()");

  universe_ = new Universe(this);
  world_parameters_ = NULL;
	return;
}

//=============================================================================
/**
  @fn     WorldGenerator::~WorldGenerator()
  @brief  destructor
**/
//=============================================================================
WorldGenerator::~WorldGenerator() {
  LOG_DEBUG("entered: WorldGenerator::~WorldGenerator()");

  delete world_parameters_;
  delete universe_;
}

//=============================================================================
// FUNCTIONS
//=============================================================================
/**
@fn     WorldGenerator::getInstance()
@brief  returns the singleton instance of WorldGenerator
@return singleton instance of WorldGenerator
**/
//=============================================================================
WorldGenerator* WorldGenerator::getInstance() {
  LOG_DEBUG("entered: WorldGenerator::getInstace()");

  if(instance_ == NULL) {
    instance_ = new WorldGenerator();
  }
  return instance_;
}

//=============================================================================
/**
@fn     WorldGenerator::get_world_parameters()
@brief  getter for world_parameters_
@return world_parameters
**/
//=============================================================================
ParameterContainer WorldGenerator::get_world_parameters() {
  LOG_DEBUG("entered: WorldGenerator::get_world_parameters()");

  if(world_parameters_ == NULL) {
    world_parameters_ = new ParameterContainer();
  }
  return *world_parameters_;
}

//=============================================================================
/**
@fn     WorldGenerator::set_world_parameters()
@brief  setter for world_parameters_
@param  world_parameters    contains the new world parameters
@return 1 = OK; 0 = Error
**/
//=============================================================================
bool WorldGenerator::set_world_parameters(ParameterContainer world_parameters) {
  LOG_DEBUG("entered: WorldGenerator::set_world_parameters()");

  delete world_parameters_;
  world_parameters_ = new ParameterContainer(world_parameters);
  if(world_parameters_->universe_size_ != world_parameters.universe_size_) {
    return 0;
  }
  return 1;
}

//=============================================================================
/**
@fn     WorldGenerator::doTheGodJob()
@brief  starts the universe generation process
@return 1 = OK; 0 = Error
**/
//=============================================================================
bool WorldGenerator::doTheGodJob() {
  LOG_DEBUG("entered: WorldGenerator::doTheGodJob()");

  get_world_parameters();
  bool result = universe_->generateWorld();
  if(result) {
    LOG_DEBUG("Darwinism FTW!");
  }
  else {
    LOG_DEBUG("Darwinism failed hard");
  }
  return result;
}