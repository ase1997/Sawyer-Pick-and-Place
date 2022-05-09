
"use strict";

let MotionStatus = require('./MotionStatus.js');
let WaypointOptions = require('./WaypointOptions.js');
let WaypointSimple = require('./WaypointSimple.js');
let InterpolatedPath = require('./InterpolatedPath.js');
let Trajectory = require('./Trajectory.js');
let TrajectoryAnalysis = require('./TrajectoryAnalysis.js');
let TrackingOptions = require('./TrackingOptions.js');
let JointTrackingError = require('./JointTrackingError.js');
let TrajectoryOptions = require('./TrajectoryOptions.js');
let EndpointTrackingError = require('./EndpointTrackingError.js');
let Waypoint = require('./Waypoint.js');
let MotionCommandActionResult = require('./MotionCommandActionResult.js');
let MotionCommandResult = require('./MotionCommandResult.js');
let MotionCommandFeedback = require('./MotionCommandFeedback.js');
let MotionCommandGoal = require('./MotionCommandGoal.js');
let MotionCommandActionGoal = require('./MotionCommandActionGoal.js');
let MotionCommandActionFeedback = require('./MotionCommandActionFeedback.js');
let MotionCommandAction = require('./MotionCommandAction.js');

module.exports = {
  MotionStatus: MotionStatus,
  WaypointOptions: WaypointOptions,
  WaypointSimple: WaypointSimple,
  InterpolatedPath: InterpolatedPath,
  Trajectory: Trajectory,
  TrajectoryAnalysis: TrajectoryAnalysis,
  TrackingOptions: TrackingOptions,
  JointTrackingError: JointTrackingError,
  TrajectoryOptions: TrajectoryOptions,
  EndpointTrackingError: EndpointTrackingError,
  Waypoint: Waypoint,
  MotionCommandActionResult: MotionCommandActionResult,
  MotionCommandResult: MotionCommandResult,
  MotionCommandFeedback: MotionCommandFeedback,
  MotionCommandGoal: MotionCommandGoal,
  MotionCommandActionGoal: MotionCommandActionGoal,
  MotionCommandActionFeedback: MotionCommandActionFeedback,
  MotionCommandAction: MotionCommandAction,
};
