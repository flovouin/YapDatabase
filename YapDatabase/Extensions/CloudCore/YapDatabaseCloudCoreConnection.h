/**
 * Copyright Deusty LLC.
**/

#import <Foundation/Foundation.h>
#import "YapDatabaseExtensionConnection.h"

NS_ASSUME_NONNULL_BEGIN

@class YapDatabaseCloudCore;

@interface YapDatabaseCloudCoreConnection : YapDatabaseExtensionConnection

/**
 * Returns the parent instance.
**/
@property (nonatomic, strong, readonly) YapDatabaseCloudCore *cloudCore;

- (id)initWithParent:(YapDatabaseCloudCore *)inParent databaseConnection:(YapDatabaseConnection *)inDbC;
- (void)prepareForReadWriteTransaction;

@end

NS_ASSUME_NONNULL_END
