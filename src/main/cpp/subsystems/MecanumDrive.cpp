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
    mFrontLeftMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mRearLeftMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mFrontRightMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    mRearRightMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void MecanumDrive::drive() {
    double x = mpDriverController->GetRawAxis(0); // kLeftX
    double y = mpDriverController->GetRawAxis(1); // kLeftY

    double rotation = mpDriverController->GetRawAxis(4); // kRightX

    mMecanumDrive.DriveCartesian(x, y, rotation);
}

// This method will be called once per scheduler run
void MecanumDrive::Periodic() {}
