// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.1 clang-703.0.29)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import CoreLocation;
@import ObjectiveC;
@import CoreBluetooth;
@import UIKit;
@import CoreGraphics;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

@interface CLBeacon (SWIFT_EXTENSION(HiBeacons))

/// Returns a specially-formatted description of the beacon's characteristics.
///
/// :returns: The beacon's description.
- (NSString * _Nonnull)fullDetails;
@end

@class CLLocationManager;
@class CLBeaconRegion;


/// Provides a base class for all the operations that the app can perform.
SWIFT_CLASS("_TtC9HiBeacons12NATOperation")
@interface NATOperation : NSObject <CLLocationManagerDelegate>

/// An instance of CLLocationManager to provide monitoring and ranging facilities.
@property (nonatomic, strong) CLLocationManager * _Nonnull locationManager;

/// The beacon region that will be used as the reference for monitoring and ranging.
@property (nonatomic, readonly, strong) CLBeaconRegion * _Nonnull beaconRegion;

/// Sets the location manager delegate to self. It is called when an instance is ready to process location manager delegate calls.
- (void)activateLocationManagerNotifications;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class CBPeripheralManager;


/// NATAdvertisingOperation contains all the process logic required to successfully advertising the presence of a a specific beacon (and region) to nearby devices.
SWIFT_CLASS("_TtC9HiBeacons23NATAdvertisingOperation")
@interface NATAdvertisingOperation : NATOperation

/// An instance of a CBPeripheralManager, which is used for advertising a beacon to nearby devices.
@property (nonatomic, strong) CBPeripheralManager * _Nonnull peripheralManager;

/// Starts the beacon advertising process.
- (void)startAdvertisingBeacon;

/// Turns on advertising (after all the checks have been passed).
- (void)turnOnAdvertising;

/// Stops the monitoring process.
- (void)stopAdvertisingBeacon;

/// Sets the peripheral manager delegate to self. It is called when an instance is ready to process peripheral manager delegate calls.
- (void)activatePeripheralManagerNotifications;

/// Sets the peripheral manager delegate to nil. It is called when an instance is ready to stop processing peripheral manager delegate calls.
- (void)deactivatePeripheralManagerNotifications;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSError;

@interface NATAdvertisingOperation (SWIFT_EXTENSION(HiBeacons)) <CBPeripheralManagerDelegate>
- (void)peripheralManagerDidStartAdvertising:(CBPeripheralManager * _Nonnull)peripheral error:(NSError * _Nullable)error;
- (void)peripheralManagerDidUpdateState:(CBPeripheralManager * _Nonnull)peripheral;
@end

@class UIWindow;
@class UIApplication;


/// The app delegate
SWIFT_CLASS("_TtC9HiBeacons20NATHiBeaconsDelegate")
@interface NATHiBeaconsDelegate : UIResponder <UIApplicationDelegate>

/// The notification name for any watch-originating operation
+ (NSString * _Nonnull)NATHiBeaconsWatchNotificationName;

/// The main window
@property (nonatomic, strong) UIWindow * _Nullable window;
- (BOOL)application:(UIApplication * _Nonnull)application willFinishLaunchingWithOptions:(NSDictionary * _Nullable)launchOptions;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



/// NATMonitoringOperation contains all the process logic required to successfully monitor for events related to detecting a specific beacon region.
SWIFT_CLASS("_TtC9HiBeacons22NATMonitoringOperation")
@interface NATMonitoringOperation : NATOperation

/// Starts the beacon region monitoring process.
- (void)startMonitoringForBeacons;

/// Turns on monitoring (after all the checks have been passed).
- (void)turnOnMonitoring;

/// Stops the monitoring process.
- (void)stopMonitoringForBeacons;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class CLRegion;

@interface NATMonitoringOperation (SWIFT_EXTENSION(HiBeacons))
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didEnterRegion:(CLRegion * _Null_unspecified)region;
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didExitRegion:(CLRegion * _Null_unspecified)region;
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion * _Null_unspecified)region;
@end


@class UIActivityIndicatorView;
@class NSCoder;


/// The custom cell that is used for presenting the user with the three possible app operations.
SWIFT_CLASS("_TtC9HiBeacons16NATOperationCell")
@interface NATOperationCell : UITableViewCell
@property (nonatomic, weak) IBOutlet UIActivityIndicatorView * _Null_unspecified activityIndicator;
- (void)updateConstraints;
- (void)layoutSubviews;
- (nonnull instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString * _Nullable)reuseIdentifier OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end



/// NATRangingOperation contains all the process logic required to successfully monitor for events related to ranging beacons belonging to a specific beacon region.
SWIFT_CLASS("_TtC9HiBeacons19NATRangingOperation")
@interface NATRangingOperation : NATOperation

/// Starts the beacon ranging process.
- (void)startRangingForBeacons;

/// Turns on ranging (after all the checks have been passed).
- (void)turnOnRanging;

/// Stops the ranging process.
- (void)stopRangingForBeacons;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NATRangingOperation (SWIFT_EXTENSION(HiBeacons))
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;
- (void)locationManager:(CLLocationManager * _Null_unspecified)manager didRangeBeacons:(NSArray * _Null_unspecified)beacons inRegion:(CLBeaconRegion * _Null_unspecified)region;
@end

@class UITableView;


/// The main view controller, which basically manages the UI, triggers operations and updates its views.
SWIFT_CLASS("_TtC9HiBeacons17NATViewController")
@interface NATViewController : UIViewController

/// The main table view containing the operation cells, and optionally the ranged beacons.
@property (nonatomic, weak) IBOutlet UITableView * _Null_unspecified beaconTableView;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class UISwitch;

@interface NATViewController (SWIFT_EXTENSION(HiBeacons))

/// Starts/stops the monitoring operation, depending on the state of the given switch.
///
/// :param: monitoringSwitch The monitoring UISwitch instance.
- (void)changeMonitoringState:(UISwitch * _Nonnull)monitoringSwitch;

/// Starts/stops the advertising operation, depending on the state of the given switch.
///
/// :param: advertisingSwitch The advertising UISwitch instance.
- (void)changeAdvertisingState:(UISwitch * _Nonnull)advertisingSwitch;

/// Starts/stops the ranging operation, depending on the state of the given switch.
///
/// :param: rangingSwitch The ranging UISwitch instance.
- (void)changeRangingState:(UISwitch * _Nonnull)rangingSwitch;
@end


@interface NATViewController (SWIFT_EXTENSION(HiBeacons))

/// Triggered by the advertising operation when it has started successfully and turns the advertising switch and the activity indicator on.
- (void)advertisingOperationDidStartSuccessfully;

/// Triggered by the advertising operation when it has stopped successfully and turns the activity indicator off.
- (void)advertisingOperationDidStopSuccessfully;

/// Triggered by the advertising operation when ithas failed to start and turns the advertising switch off.
- (void)advertisingOperationDidFailToStart;
@end


@interface NATViewController (SWIFT_EXTENSION(HiBeacons))

/// Triggered by the ranging operation when it has started successfully. It turns the ranging switch on and resets the detectedBeacons array.
- (void)rangingOperationDidStartSuccessfully;

/// Triggered by the ranging operation when it has failed to start and turns the ranging switch off.
- (void)rangingOperationDidFailToStart;

/// Triggered by the ranging operation when it has failed to start due to the last authorization denial.
///
/// It turns the ranging switch off and presents a UIAlertView to prompt the user to change their location
/// access settings.
- (void)rangingOperationDidFailToStartDueToAuthorization;

/// Triggered by the ranging operation when it has stopped successfully. It updates the beacon table view to reflect that the ranging has stopped.
- (void)rangingOperationDidStopSuccessfully;

/// Triggered by the ranging operation when it has detected beacons belonging to a specific given beacon region.
///
/// It updates the table view to show the newly-found beacons.
///
/// :param: beacons An array of provided beacons that the ranging operation detected.
/// :param: region A provided region whose beacons the operation is trying to range.
- (void)rangingOperationDidRangeBeacons:(NSArray * _Null_unspecified)beacons inRegion:(CLBeaconRegion * _Null_unspecified)region;
@end

@class NSIndexPath;
@class NSIndexSet;

@interface NATViewController (SWIFT_EXTENSION(HiBeacons))

/// Returns an array of NSIndexPath instances for the given beacons, which are to be removed from the table view.
///
/// Not all of the given beacons will actually be removed. It will be determined by comparing with the currently
/// detected beacons.
///
/// :param: beacons An array of CLBeacon objects.
/// :returns: An array of NSIndexPaths corresponding to positions in the table view where these beacons are.
- (NSArray<NSIndexPath *> * _Nullable)indexPathsOfRemovedBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons;

/// Returns an array of NSIndexPath instances for the given beacons, which are to be inserted in the table view.
///
/// Not all of the given beacons will actually be inserted. It will be determined by comparing with all the
/// currently detected beacons.
///
/// :param: beacons An array of CLBeacon objects.
/// :returns: An array of NSIndexPaths corresponding to positions in the table view where these beacons are.
- (NSArray<NSIndexPath *> * _Nullable)indexPathsOfInsertedBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons;

/// Returns an array of NSIndexPath instances for the given beacons.
///
/// :param: beacons An array of CLBeacon objects.
/// :returns: An array of NSIndexPaths corresponding to positions in the table view.
- (NSArray<NSIndexPath *> * _Nonnull)indexPathsForBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons;

/// Returns an NSIndexSet instance of the inserted sections in the table view or nil.
///
/// :returns: An NSIndexSet instance or nil.
- (NSIndexSet * _Nullable)insertedSections;

/// Returns an NSIndexSet instance of the deleted sections in the table view or nil.
///
/// :returns: An NSIndexSet instance or nil.
- (NSIndexSet * _Nullable)deletedSections;

/// Returns an array of CLBeacon instances that has been all its duplicates filtered out.
///
/// Duplicates may appear during ranging; this may happen temporarily if the originating device changes its
/// Bluetooth ID.
///
/// :param: beacons An array of CLBeacon objects.
/// :returns: An array of CLBeacon objects.
- (NSArray<CLBeacon *> * _Nonnull)filteredBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons;
@end


@interface NATViewController (SWIFT_EXTENSION(HiBeacons))

/// Triggered by the monitoring operation when it has started successfully and turns the monitoring switch and activity indicator on.
- (void)monitoringOperationDidStartSuccessfully;

/// Triggered by the monitoring operation when it has stopped successfully and turns the activity indicator off.
- (void)monitoringOperationDidStopSuccessfully;

/// Triggered by the monitoring operation when it has failed to start and turns the monitoring switch off.
- (void)monitoringOperationDidFailToStart;

/// Triggered by the monitoring operation when it has failed to start due to the last authorization denial.
///
/// It turns the monitoring switch off and presents a UIAlertView to prompt the user to change their location
/// access settings.
- (void)monitoringOperationDidFailToStartDueToAuthorization;

/// Triggered by the monitoring operation when it has detected entering the provided region. It emits a local notification.
///
/// :param: region The provided region that the monitoring operation detected.
- (void)monitoringOperationDidDetectEnteringRegion:(CLBeaconRegion * _Nonnull)region;

/// Emits a UILocalNotification with information about the given region.
///
/// Note that major and minor are not available at the monitoring stage.
///
/// :param: region The given CLBeaconRegion instance.
- (void)sendLocalNotificationForBeaconRegion:(CLBeaconRegion * _Nonnull)region;
@end

@class UIView;

@interface NATViewController (SWIFT_EXTENSION(HiBeacons)) <UITableViewDataSource, UITableViewDelegate>
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section;
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForHeaderInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView * _Nonnull)tableView heightForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (UIView * _Nullable)tableView:(UITableView * _Nonnull)tableView viewForHeaderInSection:(NSInteger)section;
@end

#pragma clang diagnostic pop
