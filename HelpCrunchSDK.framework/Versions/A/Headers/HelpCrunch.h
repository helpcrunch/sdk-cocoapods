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

FOUNDATION_EXTERN NSString *const HC_UserNameAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserEmailAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserPhoneAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserIdAttributeName;
FOUNDATION_EXTERN NSString *const HC_UserSignatureAttributeName;
FOUNDATION_EXTERN NSString *const HC_CustomDataAttributeName;

FOUNDATION_EXTERN NSString *const HC_OpenLinkNotification;

typedef void (^HCCompletionHandler)(BOOL succeeded, NSError *error);
typedef void (^HCImageAttachmentPressedHandler)(NSString *imageUrlString);

@interface HelpCrunch : NSObject

+ (void)initForOrganization:(NSString *)organizationDomain withAttributes:(NSDictionary *)attributes completionHandler:(HCCompletionHandler)completionHandler;

+ (void)showFromController:(UIViewController *)controller;
+ (BOOL)isShowing;

+ (void)restoreFromBackground;

+ (void)registerForRemoteNotifications;
+ (void)setDeviceToken:(NSData *)deviceToken;

+ (BOOL)didReceiveRemoteNotification:(NSDictionary *)userInfo;
+ (BOOL)didReceiveRemoteNotificationWithLaunchOptions:(NSDictionary *)launchOptions;

+ (void)useDefaultAlertForRemoteNotification:(BOOL)useDefaultAlert; // Defaults to YES

+ (void)updateUser:(NSDictionary *)attributes completionHandler:(HCCompletionHandler )completionHandler;
+ (void)customerNameRequired:(BOOL)required; // Defaults to YES.
+ (void)logout:(HCCompletionHandler)completionHandler;

+ (NSUInteger)numberOfUnreadMessages;
+ (void)checkUnreadMessages:(void (^)(NSUInteger unread))callbackBlock;

+ (void)enableNetworkActivityIndicator:(BOOL)enable; // Defaults to NO.

+ (NSString *)appVersion;
+ (NSString *)sdkVersion;

+ (void)imageAttachmentPressedHandler:(HCImageAttachmentPressedHandler )handler;

@end
