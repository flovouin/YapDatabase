#import <Foundation/Foundation.h>

#import "YapDatabaseTransaction.h"

NS_ASSUME_NONNULL_BEGIN

@interface YapDatabaseExtensionConnection : NSObject

/**
 * This class is abstract and has no public API.
 * See concrete implementations such as YapDatabaseViewConnection, YapDatabaseSecondaryIndexConnection, etc.
**/

- (id)newReadTransaction:(YapDatabaseReadTransaction *)databaseTransaction;
- (id)newReadWriteTransaction:(YapDatabaseReadWriteTransaction *)databaseTransaction;

@end

NS_ASSUME_NONNULL_END
