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
	double x = flip * mSpeed * getAxis(0, true); // kLeftX
	double y = flip * mSpeed * -1.00 * getAxis(1, true); // kLeftY

	double rotation = 0.75 * getAxis(4); // kRightX

	mMecanumDrive.DriveCartesian(x, y, rotation);
    printf("x: %f         y: %f        rot: %f\n", x, y, rotation);
}

void MecanumDrive::fasterDrive() {
	mSpeed += 0.05;
    if (mSpeed > 1.0) mSpeed = 1.0;
}

void MecanumDrive::slowerDrive() {
	mSpeed -= 0.05;
    if (mSpeed < 0.15) mSpeed = 0.15;
}

void MecanumDrive::flipDrive() {
	mFlipped = !mFlipped;
}

// This method will be called once per scheduler run
void MecanumDrive::Periodic() {}

// Deadzones
double MecanumDrive::getAxis(int axis, bool square) {
    double speed = mpDriverController->GetRawAxis(axis);
    if (-0.1 < speed && speed < 0.1) { speed = 0; }
    return square ? speed*speed : speed;
}