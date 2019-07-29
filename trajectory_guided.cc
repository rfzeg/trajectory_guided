/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>

namespace gazebo
{
  class TrajectoryGuided : public ModelPlugin
  {
    public: void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {
      // Store the pointer to the model
      this->model = _parent;

        // create the animation
        gazebo::common::PoseAnimationPtr anim(
              // name the animation "test",
              // make it last 10 seconds,
              // and set it on a repeat loop
              new gazebo::common::PoseAnimation("test", 32.0, true));

        gazebo::common::PoseKeyFrame *key;
    
       // Trajectory goes through 12 points and takes 32s in between them

       // set starting location of the model
        key = anim->CreateKeyFrame(0);
        key->Translation(ignition::math::Vector3d(0, -20, 0)); // midway
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        // set waypoint location after 2 seconds
        key = anim->CreateKeyFrame(2.0);
        key->Translation(ignition::math::Vector3d(30, -20, 0)); // in
        key->Rotation(ignition::math::Quaterniond(0, 0, 0));

        key = anim->CreateKeyFrame(6.0);
        key->Translation(ignition::math::Vector3d(40, -10, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.5707)); // out

        key = anim->CreateKeyFrame(8.0);
        key->Translation(ignition::math::Vector3d(40, 0, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.5707)); // midway

        key = anim->CreateKeyFrame(10.0);
        key->Translation(ignition::math::Vector3d(40, 10, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 1.5707)); // in

        key = anim->CreateKeyFrame(14.0);
        key->Translation(ignition::math::Vector3d(30, 20, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14159)); // out

        key = anim->CreateKeyFrame(16.0);
        key->Translation(ignition::math::Vector3d(0, 20, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14159)); // midway

        key = anim->CreateKeyFrame(18.0);
        key->Translation(ignition::math::Vector3d(-30, 20, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 3.14159)); // in

        key = anim->CreateKeyFrame(22.0);
        key->Translation(ignition::math::Vector3d(-40, 10, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71239)); // out

        key = anim->CreateKeyFrame(24.0);
        key->Translation(ignition::math::Vector3d(-40, 0, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71239)); // midway

        key = anim->CreateKeyFrame(26.0);
        key->Translation(ignition::math::Vector3d(-40, -10, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 4.71239)); // in

        key = anim->CreateKeyFrame(30.0);
        key->Translation(ignition::math::Vector3d(-30, -20, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 6.28319)); // out

        // set final location equal to starting location
        key = anim->CreateKeyFrame(32.0);
        key->Translation(ignition::math::Vector3d(0, -20, 0));
        key->Rotation(ignition::math::Quaterniond(0, 0, 6.28319)); // midway

        // set the animation
        _parent->SetAnimation(anim);
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(TrajectoryGuided)
}
