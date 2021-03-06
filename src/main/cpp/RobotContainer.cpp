// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
	// Initialize all of your commands and subsystems here

	mMecanumDrive.SetDefaultCommand(std::move(mRunMecanumDrive));
	mMecanumDrive.setController(&mDriverController);

	// Configure the button bindings
	ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
	// Configure your button bindings here
	mDriverUpDPad.WhenPressed(mFasterDriveCommand);
	mDriverDownDPad.WhenPressed(mSlowerDriveCommand);
	mDriverButtonRMenu.WhenPressed(mFlipDriveCommand);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
	// An example command will be run in autonomous
	return nullptr;
}
