// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>
#include <frc/drive/MecanumDrive.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

class MecanumDrive : public frc2::SubsystemBase {
 public:
  MecanumDrive();
  void setController(frc::XboxController *pDriverController) {
   mpDriverController = pDriverController;
  }

  void drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  frc::XboxController *mpDriverController;

  WPI_TalonFX mFrontLeftMotor;
  WPI_TalonFX mRearLeftMotor;
  WPI_TalonFX mFrontRightMotor;
  WPI_TalonFX mRearRightMotor;

  frc::MecanumDrive mMecanumDrive{mFrontLeftMotor, mRearLeftMotor, mFrontRightMotor, mRearRightMotor};
};