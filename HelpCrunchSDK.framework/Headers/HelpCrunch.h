#import <UIKit/UIKit.h>

#import "HCSConfiguration.h"
#import "HCSTheme.h"
#import "HCSUser.h"

#pragma mark - SDK Notification Events

/**
 Called on tap on corresponding data type. URL will be in userInfo[@"data"]
 */
FOUNDATION_EXTERN NSString *const HCSURLNotification;
FOUNDATION_EXTERN NSString *const HCSImageURLNotification;
FOUNDATION_EXTERN NSString *const HCSFileURLNotification;

/**
 Will be called on user's first sent message
 */
FOUNDATION_EXTERN NSString *const HCSUserStartedChatNotification;

/**
 Will be called from both Welcome and Chat screens
 */
FOUNDATION_EXTERN NSString *const HCSUserClosedChatNotification;

/**
 Will be called each time number of unread messages changes. Could be called outside of main thread.
 */
FOUNDATION_EXTERN NSString *const HCSUnreadMessagesNotification;

static NSString *const HCSSDKVersion = @"2.0";

typedef void (^HCSCompletionHandler)(NSError * _Nullable error);

@interface HelpCrunch : NSObject

#pragma mark - State of the SDK

/**
 Initialize HelpCrunch sdk. You must call this method before any other SDK methods (except Theme methods)

 @param configuration Organization, ApplicationId and ApplicationSecret are required parameters. Everything else - optional.
 @param user You can apply user from beginning. If needed, use updateUser:completion method
 @param completion Will be called when HelpCrunch SDK completed initializtion
 */
+ (void)initWithConfiguration:(HCSConfiguration *)configuration
                         user:(HCSUser * _Nullable)user
                   completion:(HCSCompletionHandler _Nullable)completion;

+ (void)bindConfiguration:(HCSConfiguration *)configuration;
+ (HCSConfiguration *)configuration;

/**
 Logout current user and remove current chat.
 If you require some user attributes, user will be prompted with Welcome screen on next showFromController:completion: call
 @param completion will be executed on successfull logout
 */
+ (void)logoutWithCompletion:(HCSCompletionHandler _Nullable)completion;

+ (void)updateUser:(HCSUser * _Nullable)user completion:(HCSCompletionHandler)completion;

/**
 Number of unread messages. Will be 0 after [showFrom:completion] call
 */
+ (NSUInteger)numberOfUnreadMessages;

#pragma mark - Theming

+ (HCSTheme *)currentTheme;
+ (HCSTheme *)darkTheme;
+ (HCSTheme *)defaultTheme;

+ (void)bindTheme:(HCSTheme *)theme;

#pragma mark - View Controllers

/**
 Returns true if Welcome or Chat view controllers currently on the screen
 */
+ (BOOL)isVisible;

/**
 Shows Welcome or Chat view controller presented from given View Controller
 
 @param viewController - view controller to be presented from
 @param completion - block, that will be executed on completion of presenting animation
 */
+ (void)showFromController:(UIViewController *)viewController completion:(HCSCompletionHandler)completion;

/**
 Will dismiss HelpCrunch screens if any presented.
 Completion block won't fire if no HelpCrunch screen presented. Use [isVisible] method to check.
 
 @param completion - block, that will be executed on completion of dismissing animation.
 */
+ (void)closeChatWithCompletion:(HCSCompletionHandler)completion;

#pragma mark - Push Notifications

/**
 Standard UserNotification permissions request. Use it only if you're not asking for permissions by yourself.
 */
+ (void)registerForRemoteNotifications;

/**
 Add your push notification device token to HelpCrunch

 @param deviceToken raw token data from AppDelegate's didRegisterForRemoteNotificationsWithDeviceToken: method
 */
+ (void)setDeviceToken:(NSData *)deviceToken;

+ (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (BOOL)didReceiveRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions;
+ (BOOL)isHelpCrunchNotification:(NSDictionary *)notification;

+ (void)trackEvent:(NSString *)event;

@end

