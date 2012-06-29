//
//  KSDatabase.h
//  QuestionEditor
//
//  Created by Graeme Knopp on 12-06-29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSManagedObject+utils.h"

@interface KSDatabase : NSObject

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (strong, nonatomic) NSString* currentDatabase;

+(KSDatabase*) defaultDatabase;


-(void) save;

@end
