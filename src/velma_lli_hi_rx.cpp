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

#include <rtt/Component.hpp>
#include <rtt/Logger.hpp>

#include "velma_lli_hi_rx.h"

using namespace RTT;

VelmaLLIHiRx::VelmaLLIHiRx(const std::string &name) :
    TaskContext(name, PreOperational),
    out_(*this)
{
    this->ports()->addEventPort("status_INPORT", port_status_in_);
}

bool VelmaLLIHiRx::configureHook() {
    return true;
}

bool VelmaLLIHiRx::startHook() {
//    RESTRICT_ALLOC;

//    UNRESTRICT_ALLOC;
    return true;
}

void VelmaLLIHiRx::stopHook() {
}

void VelmaLLIHiRx::updateHook() {
    Logger::In in("VelmaLLIHiRx::updateHook");
//    RESTRICT_ALLOC;
    // write outputs
//    UNRESTRICT_ALLOC;
    uint32_t test_prev = status_in_.test;

    if (port_status_in_.read(status_in_) == NewData) {

        if (test_prev == status_in_.test) {
            Logger::log() << Logger::Warning << "executed updateHook twice for the same packet" << Logger::endl;
        }

        out_.writePorts(status_in_);

        TaskContext::PeerList l = this->getPeerList();
        for (TaskContext::PeerList::const_iterator it = l.begin(); it != l.end(); ++it) {
            this->getPeer( (*it) )->getActivity()->trigger();
        }
        Logger::log() << Logger::Debug << "received new data" << Logger::endl;
    }
    else {
        Logger::log() << Logger::Info << "received old data" << Logger::endl;
    }
}

