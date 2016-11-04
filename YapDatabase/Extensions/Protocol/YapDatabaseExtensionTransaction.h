#import <Foundation/Foundation.h>

#import "YapCollectionKey.h"

NS_ASSUME_NONNULL_BEGIN

@interface YapDatabaseExtensionTransaction : NSObject

/**
 * This class is abstract and has no public API.
 * See concrete implementations such as YapDatabaseViewTransaction, YapDatabaseSecondaryIndexTransaction, etc.
**/

- (void)didInsertObject:(id __unused)object
       forCollectionKey:(YapCollectionKey __unused *)collectionKey
           withMetadata:(id __unused)metadata
                  rowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - setObject:forKey:inCollection:
 * - setObject:forKey:inCollection:withMetadata:
 * - setObject:forKey:inCollection:withMetadata:serializedObject:serializedMetadata:
 *
 * The row is being modified, meaning there is already an entry for the collection/key tuple which is being modified.
**/
- (void)didUpdateObject:(id __unused)object
       forCollectionKey:(YapCollectionKey __unused *)collectionKey
           withMetadata:(id __unused)metadata
                  rowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - replaceObject:forKey:inCollection:
 * - replaceObject:forKey:inCollection:withSerializedObject:
 *
 * There is already a row for the collection/key tuple, and only the object is being modified (metadata untouched).
**/
- (void)didReplaceObject:(id __unused)object
        forCollectionKey:(YapCollectionKey __unused *)collectionKey
               withRowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - replaceMetadata:forKey:inCollection:
 * - replaceMetadata:forKey:inCollection:withSerializedMetadata:
 *
 * There is already a row for the collection/key tuple, and only the metadata is being modified (object untouched).
**/
- (void)didReplaceMetadata:(id __unused)metadata
          forCollectionKey:(YapCollectionKey __unused *)collectionKey
                 withRowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - touchObjectForKey:inCollection:collection:
**/
- (void)didTouchObjectForCollectionKey:(YapCollectionKey __unused *)collectionKey withRowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - touchMetadataForKey:inCollection:
**/
- (void)didTouchMetadataForCollectionKey:(YapCollectionKey __unused *)collectionKey withRowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - touchRowForKey:inCollection:
**/
- (void)didTouchRowForCollectionKey:(YapCollectionKey *)collectionKey withRowid:(int64_t)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction
 * - removeObjectForKey:inCollection:
**/
- (void)didRemoveObjectForCollectionKey:(YapCollectionKey __unused *)collectionKey withRowid:(int64_t __unused)rowid;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to the following method(s) in YapDatabaseReadWriteTransaction:
 * - removeObjectsForKeys:inCollection:
 * - removeAllObjectsInCollection:
 *
 * IMPORTANT:
 *   The number of items passed to this method has the following guarantee:
 *   count <= (SQLITE_LIMIT_VARIABLE_NUMBER - 1)
 *
 * The YapDatabaseReadWriteTransaction will inspect the list of keys that are to be removed,
 * and then loop over them in "chunks" which are readily processable for extensions.
**/
- (void)didRemoveObjectsForKeys:(NSArray __unused *)keys
                   inCollection:(NSString __unused *)collection
                     withRowids:(NSArray __unused *)rowids;

/**
 * Subclasses MUST implement this method.
 * YapDatabaseReadWriteTransaction Hook, invoked post-op.
 *
 * Corresponds to [transaction removeAllObjectsInAllCollections].
**/
- (void)didRemoveAllObjectsInAllCollections;

@end

NS_ASSUME_NONNULL_END
