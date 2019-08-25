//
//  HelpCrunch.h
//  HelpCrunchSDK
//
//
//  Copyright (c) 2015 HelpCrunch. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

FOUNDATION_EXTERN NSString *const HC_ApplicationIdAttributeName;
FOUNDATION_EXTERN NSString *const HC_ApplicationSecretAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserAttributeName;
FOUNDATION_EXTERN NSString *const HC_ApplicationLogging;

FOUNDATION_EXTERN NSString *const HC_UserNameAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserEmailAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserPhoneAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserIdAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserSignatureAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserCompanyAttributeName;
FOUNDATION_EXTERN NSString *const HC_CustomDataAttributeName;

FOUNDATION_EXTERN NSString *const HC_OpenLinkNotification;

static NSString *const HC_SDKVersion = @"1.1.15";

/**
 Fires when user press 'Done' button on the chat view controller
 
 @since version 1.0.44
 */
FOUNDATION_EXTERN NSString *const HC_UserClosedChatNotification;

/**
  Notifying about chat view controller's events
 
  @since version 1.0.44
 */
@protocol HelpCrunchPresenterDelegate <NSObject>
@optional
  
/**
  Called when user press 'Done' button on the chat view controller
  Use delegate or notification 'HC_UserClosedChatNotification' approaches according to your wish
 
  @since version 1.0.44
 */
- (void)userDidCloseChat;
@end

typedef void (^HCCompletionHandler)(BOOL succeeded, NSError *error);
typedef void (^HCImageAttachmentPressedHandler)(NSString *imageUrlString);

@interface HelpCrunch : NSObject

+ (void)initForOrganization:(NSString *)organizationDomain withAttributes:(NSDictionary *)attributes completionHandler:(HCCompletionHandler)completionHandler;

+ (void)showFromController:(UIViewController *)controller;
  
/**
 Chat view controller will be displayed by calling -[UIViewController presentViewController:animated:]
 
 @since version 1.0.44
 */
+ (void)showFromController:(UIViewController *)controller delegate:(id<HelpCrunchPresenterDelegate>)delegate;
  
+ (BOOL)isShowing;
+ (BOOL)closeChatIfVisible;

+ (void)restoreFromBackground;

+ (void)registerForRemoteNotifications;
+ (void)setDeviceToken:(NSData *)deviceToken;

+ (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (BOOL)didReceiveRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions;

+ (void)useDefaultAlertForRemoteNotification:(BOOL)useDefaultAlert; // Defaults to YES

+ (void)updateUser:(NSDictionary *)attributes completionHandler:(HCCompletionHandler)completionHandler;
+ (void)customerNameRequired:(BOOL)required; // Defaults to YES.
+ (void)logout:(HCCompletionHandler)completionHandler;

+ (NSUInteger)numberOfUnreadMessages;

/**
 Add callback on any unreadMessages changes

 @param callbackBlock - will be called each time number of unread messages changes. Could be called outside of main thread.
 */
+ (void)checkUnreadMessages:(void (^)(NSUInteger unread))callbackBlock;

+ (void)enableNetworkActivityIndicator:(BOOL)enable; // Defaults to NO.

+ (void)imageAttachmentPressedHandler:(HCImageAttachmentPressedHandler )handler;

+ (NSString *)appVersion;

@end
