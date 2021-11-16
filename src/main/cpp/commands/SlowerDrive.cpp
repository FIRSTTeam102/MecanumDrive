// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SlowerDrive.h"

SlowerDrive::SlowerDrive(MecanumDrive* pMecanumDrive): mpMecanumDrive(pMecanumDrive) {
	// Use addRequirements() here to declare subsystem dependencies.
	AddRequirements(pMecanumDrive);
}

// Called when the command is initially scheduled.
void SlowerDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SlowerDrive::Execute() {
	mpMecanumDrive->slowerDrive();
}

// Called once the command ends or is interrupted.
void SlowerDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool SlowerDrive::IsFinished() {
	return true;
}