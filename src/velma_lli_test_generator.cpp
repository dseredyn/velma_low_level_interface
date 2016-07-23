/*
 Copyright (c) 2014, Robot Control and Pattern Recognition Group, Warsaw University of Technology
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the Warsaw University of Technology nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYright HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "velma_lli_test_generator.h"

VelmaLLITestGenerator::VelmaLLITestGenerator() {
    srand(0);
}

void VelmaLLITestGenerator::generate(velma_low_level_interface_msgs::VelmaLowLevelCommand &cmd, velma_low_level_interface_msgs::VelmaLowLevelStatus &status) {

    // random command
    cmd.rHand_tactileCmd = static_cast<int32_t >(rand());
    cmd.tMotor_i = static_cast<double >(rand());
    cmd.hpMotor_i = static_cast<double >(rand());
    cmd.htMotor_i = static_cast<double >(rand());
    cmd.hpMotor_q = static_cast<double >(rand());
    cmd.htMotor_q = static_cast<double >(rand());
    cmd.hpMotor_dq = static_cast<double >(rand());
    cmd.htMotor_dq = static_cast<double >(rand());

    for (int i = 0; i < 7; ++i) {
        cmd.lArm.t[i] = static_cast<double >(rand());
        cmd.rArm.t[i] = static_cast<double >(rand());
    }
    cmd.lArm.cmd = static_cast<int32_t >(rand());
    cmd.rArm.cmd = static_cast<int32_t >(rand());

    for (int i = 0; i < 4; ++i) {
        cmd.lHand.q[i] = static_cast<double >(rand());
        cmd.lHand.dq[i] = static_cast<double >(rand());
        cmd.lHand.max_p[i] = static_cast<double >(rand());
        cmd.lHand.max_i[i] = static_cast<double >(rand());
        cmd.rHand.q[i] = static_cast<double >(rand());
        cmd.rHand.dq[i] = static_cast<double >(rand());
        cmd.rHand.max_p[i] = static_cast<double >(rand());
        cmd.rHand.max_i[i] = static_cast<double >(rand());
    }

    cmd.lHand.hold = static_cast<bool >(rand()%2);
    cmd.rHand.hold = static_cast<bool >(rand()%2);

    // random status
// TODO
/*
status

# leftHandStatus
# rightHandStatus
int32 lHand_s
int32 rHand_s

# leftHandJointPosition
# rightHandJointPosition
float64 lHand_q
float64 rHand_q

# RightHandTactile.BHPressureState_OUTPORT
barrett_hand_controller_msgs/BHPressureState rHand_p

# LeftHandOptoforce.force_0_OUTPORT
# LeftHandOptoforce.force_1_OUTPORT
# LeftHandOptoforce.force_2_OUTPORT
geometry_msgs/WrenchStamped[3] lHand_f
*/
    status.tMotor_q = static_cast<double >(rand());
/*
# torsoMotorVelocity
float64 tMotor_dq = static_cast<double >(rand());

# headPanMotorPosition
float64 hpMotor_q = static_cast<double >(rand());

# headPanMotorVelocity
float64 hpMotor_dq = static_cast<double >(rand());

# headTiltMotorPosition
float64 htMotor_q = static_cast<double >(rand());

# headTiltMotorVelocity
float64 htMotor_dq = static_cast<double >(rand());

# leftArmJointPosition
# rightArmJointPosition
float64[7] lArm_q
float64[7] rArm_q

# leftArmJointVelocity
# rightArmJointVelocity
float64[7] lArm_dq
float64[7] rArm_dq

# leftArmJointTorque
# rightArmJointTorque
float64[7] lArm_t
float64[7] rArm_t

# leftArmWrench
# rightArmWrench
geometry_msgs/Wrench lArm_w
geometry_msgs/Wrench rArm_w

# leftArmMassMatrix
# rightArmMassMatrix
float64[28] lArm_mm
float64[28] rArm_mm

# leftArmGravityTorque
# rightArmGravityTorque
float64[7] lArm_gt
float64[7] rArm_gt

# leftFtSensorRawWrench
# rightFtSensorRawWrench
geometry_msgs/Wrench lFTSensor_rw
geometry_msgs/Wrench rFTSensor_rw

# leftFtSensorFastFilteredWrench
# rightFtSensorFastFilteredWrench
geometry_msgs/Wrench lFTSensor_ffw
geometry_msgs/Wrench rFTSensor_ffw

# leftFtSensorSlowFilteredWrench
# rightFtSensorSlowFilteredWrench
geometry_msgs/Wrench lFTSensor_sfw
geometry_msgs/Wrench rFTSensor_sfw

    for (int i = 0; i < 40; ++i) {
        status.rArm_tFriIntfState[i] = static_cast<uint8_t >(rand());
        status.lArm_tFriIntfState[i] = static_cast<uint8_t >(rand());
    }
    for (int i = 0; i < 36; ++i) {
        status.rArm_tFriRobotState[i] = static_cast<uint8_t >(rand());
        status.lArm_tFriRobotState[i] = static_cast<uint8_t >(rand());
    }
*/
}

std::string VelmaLLITestGenerator::toStr(const velma_low_level_interface_msgs::VelmaLowLevelCommand &cmd) {
    std::ostringstream os;
    os << cmd;
    return os.str();
}

std::string VelmaLLITestGenerator::toStr(const velma_low_level_interface_msgs::VelmaLowLevelStatus &status) {
    std::ostringstream os;
    os << status;
    return os.str();
}
