
"use strict";

let IOComponentConfiguration = require('./IOComponentConfiguration.js');
let HomingCommand = require('./HomingCommand.js');
let AnalogIOState = require('./AnalogIOState.js');
let InteractionControlCommand = require('./InteractionControlCommand.js');
let CollisionDetectionState = require('./CollisionDetectionState.js');
let SEAJointState = require('./SEAJointState.js');
let EndpointStates = require('./EndpointStates.js');
let JointCommand = require('./JointCommand.js');
let HomingState = require('./HomingState.js');
let AnalogIOStates = require('./AnalogIOStates.js');
let DigitalIOState = require('./DigitalIOState.js');
let IONodeConfiguration = require('./IONodeConfiguration.js');
let EndpointNamesArray = require('./EndpointNamesArray.js');
let IOComponentStatus = require('./IOComponentStatus.js');
let DigitalOutputCommand = require('./DigitalOutputCommand.js');
let IODeviceStatus = require('./IODeviceStatus.js');
let AnalogOutputCommand = require('./AnalogOutputCommand.js');
let CollisionAvoidanceState = require('./CollisionAvoidanceState.js');
let IODataStatus = require('./IODataStatus.js');
let NavigatorStates = require('./NavigatorStates.js');
let IODeviceConfiguration = require('./IODeviceConfiguration.js');
let RobotAssemblyState = require('./RobotAssemblyState.js');
let EndpointState = require('./EndpointState.js');
let URDFConfiguration = require('./URDFConfiguration.js');
let IONodeStatus = require('./IONodeStatus.js');
let InteractionControlState = require('./InteractionControlState.js');
let HeadState = require('./HeadState.js');
let HeadPanCommand = require('./HeadPanCommand.js');
let CameraControl = require('./CameraControl.js');
let JointLimits = require('./JointLimits.js');
let NavigatorState = require('./NavigatorState.js');
let IOStatus = require('./IOStatus.js');
let DigitalIOStates = require('./DigitalIOStates.js');
let CameraSettings = require('./CameraSettings.js');
let IOComponentCommand = require('./IOComponentCommand.js');
let CalibrationCommandAction = require('./CalibrationCommandAction.js');
let CalibrationCommandFeedback = require('./CalibrationCommandFeedback.js');
let CalibrationCommandActionFeedback = require('./CalibrationCommandActionFeedback.js');
let CalibrationCommandResult = require('./CalibrationCommandResult.js');
let CalibrationCommandGoal = require('./CalibrationCommandGoal.js');
let CalibrationCommandActionResult = require('./CalibrationCommandActionResult.js');
let CalibrationCommandActionGoal = require('./CalibrationCommandActionGoal.js');

module.exports = {
  IOComponentConfiguration: IOComponentConfiguration,
  HomingCommand: HomingCommand,
  AnalogIOState: AnalogIOState,
  InteractionControlCommand: InteractionControlCommand,
  CollisionDetectionState: CollisionDetectionState,
  SEAJointState: SEAJointState,
  EndpointStates: EndpointStates,
  JointCommand: JointCommand,
  HomingState: HomingState,
  AnalogIOStates: AnalogIOStates,
  DigitalIOState: DigitalIOState,
  IONodeConfiguration: IONodeConfiguration,
  EndpointNamesArray: EndpointNamesArray,
  IOComponentStatus: IOComponentStatus,
  DigitalOutputCommand: DigitalOutputCommand,
  IODeviceStatus: IODeviceStatus,
  AnalogOutputCommand: AnalogOutputCommand,
  CollisionAvoidanceState: CollisionAvoidanceState,
  IODataStatus: IODataStatus,
  NavigatorStates: NavigatorStates,
  IODeviceConfiguration: IODeviceConfiguration,
  RobotAssemblyState: RobotAssemblyState,
  EndpointState: EndpointState,
  URDFConfiguration: URDFConfiguration,
  IONodeStatus: IONodeStatus,
  InteractionControlState: InteractionControlState,
  HeadState: HeadState,
  HeadPanCommand: HeadPanCommand,
  CameraControl: CameraControl,
  JointLimits: JointLimits,
  NavigatorState: NavigatorState,
  IOStatus: IOStatus,
  DigitalIOStates: DigitalIOStates,
  CameraSettings: CameraSettings,
  IOComponentCommand: IOComponentCommand,
  CalibrationCommandAction: CalibrationCommandAction,
  CalibrationCommandFeedback: CalibrationCommandFeedback,
  CalibrationCommandActionFeedback: CalibrationCommandActionFeedback,
  CalibrationCommandResult: CalibrationCommandResult,
  CalibrationCommandGoal: CalibrationCommandGoal,
  CalibrationCommandActionResult: CalibrationCommandActionResult,
  CalibrationCommandActionGoal: CalibrationCommandActionGoal,
};
