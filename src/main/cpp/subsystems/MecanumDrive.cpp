// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/MecanumDrive.h"

MecanumDrive::MecanumDrive():
	mFrontLeftMotor{kFrontLeftMotor},
	mRearLeftMotor{kRearLeftMotor},
	mFrontRightMotor{kFrontRightMotor},
	mRearRightMotor{kRearRightMotor}
{
	// mFrontLeftMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	// mRearLeftMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	// mFrontRightMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
	// mRearRightMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void MecanumDrive::drive() {
	double flip = (mFlipped) ? -1.00 : 1.00;
	double x = flip * mSpeed * mpDriverController->GetRawAxis(0); // kLeftX
	double y = flip * mSpeed * mpDriverController->GetRawAxis(1); // kLeftY

	double rotation = 0.75 * mpDriverController->GetRawAxis(4); // kRightX

	mMecanumDrive.DriveCartesian(x, y, rotation);
}

void MecanumDrive::fasterDrive() {
	mSpeed += 0.05;
}

void MecanumDrive::slowerDrive() {
	mSpeed -= 0.05;
}

void MecanumDrive::flipDrive() {
	mFlipped = !mFlipped;
}

// This method will be called once per scheduler run
void MecanumDrive::Periodic() {}
