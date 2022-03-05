#pragma once

#include "RobotMap.h"

#include <frc/motorcontrol/Spark.h>
#include <frc/DoubleSolenoid.h>

#include <frc2/command/SubsystemBase.h>
#include <frc/XboxController.h>

class RapidReactRake : public frc2::SubsystemBase {
    public:
        RapidReactRake();
        void LowerRake();
        void RaiseRake();
        void EngageMotors();
        void DisengageMotors();
        void EngageRake();
        void DisengageRake();
        void EngageBallStaging();
        void DisengageBallStaging();
        void Iterate(frc::XboxController &controller);

        
        void Periodic() override;
        void SimulationPeriodic() override;

        frc::Spark m_rakeMotor{RobotMap::RAKE_MOTOR_ID};
    private:
        bool 
            m_ballStaging = false,
            m_rake = false;

        frc::DoubleSolenoid m_rakeSolenoid{RobotMap::PCM_ID, frc::PneumaticsModuleType::CTREPCM, RobotMap::RAKE_EXTEND_SOLENOID, RobotMap::RAKE_RETRACT_SOLENOID};
};