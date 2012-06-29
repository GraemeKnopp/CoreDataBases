//
//  NSManagedObject+utils.m
//  QuestionEditor
//
//  Created by Graeme Knopp on 12-06-29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "NSManagedObject+utils.h"
#import "KSDatabase.h"

@implementation NSManagedObject (utils)



#pragma mark - Create Methods


+(id) create {

	NSManagedObject* newObject = [NSEntityDescription insertNewObjectForEntityForName:NSStringFromClass([self class]) inManagedObjectContext:[KSDatabase defaultDatabase].managedObjectContext];
	return newObject;
	
}

+(id) createFromDictionary:(NSDictionary*)info {

	NSManagedObject* newObject = [self create];
	[newObject setValuesForKeysWithDictionary:info];
	return newObject;
	
}



#pragma mark - Query Methods


+(NSMutableArray*) fetch:(NSString *)predicate {

	NSManagedObjectContext* moc = [KSDatabase defaultDatabase].managedObjectContext;
	NSEntityDescription *entityDescription = [NSEntityDescription
																						entityForName:NSStringFromClass([self class]) inManagedObjectContext:moc];
	NSFetchRequest *request = [[NSFetchRequest alloc] init];
	[request setEntity:entityDescription];
	
	if (predicate != nil) {
		// Set example predicate and sort orderings...
		NSPredicate *pred = [NSPredicate predicateWithFormat:predicate];
		[request setPredicate:pred];		
	}
	
  // execute request	
	NSError *error = nil;
	NSArray *array = [moc executeFetchRequest:request error:&error];
	if ([array count] == 0) return nil;
	
	return [array mutableCopy];
}

+(NSMutableArray*) fetch:(NSString *)predicate orderBy:(NSString *)field {

	NSManagedObjectContext* moc = [KSDatabase defaultDatabase].managedObjectContext;
	NSEntityDescription *entityDescription = [NSEntityDescription
																						entityForName:NSStringFromClass([self class]) inManagedObjectContext:moc];
	NSFetchRequest *request = [[NSFetchRequest alloc] init];
	[request setEntity:entityDescription];
	
	if (predicate != nil) {
		// Set example predicate and sort orderings...
		NSPredicate *pred = [NSPredicate predicateWithFormat:predicate];
		[request setPredicate:pred];		
	}
	
	if (field != nil) {
		NSSortDescriptor *sortDescriptor = [[NSSortDescriptor alloc] initWithKey:field ascending:YES];
		NSArray *sortDescriptors = [[NSArray alloc] initWithObjects:sortDescriptor, nil];
		[request setSortDescriptors:sortDescriptors];
	}
	
  // execute request	
	NSError *error = nil;
	NSArray *array = [moc executeFetchRequest:request error:&error];
	if ([array count] == 0) return nil;
	
	return [array mutableCopy];
	
}



#pragma mark - Interface Methods


-(NSDictionary *)dictionaryInfo {
	
	NSEntityDescription* entityInfo = [NSEntityDescription entityForName:NSStringFromClass([self class]) inManagedObjectContext:[[KSDatabase defaultDatabase] managedObjectContext]];
	
	NSArray* keyArray = [[entityInfo attributesByName] allKeys];
	NSDictionary* info = [self dictionaryWithValuesForKeys:keyArray];
	return info;
	
}

-(void) remove {
	[[KSDatabase defaultDatabase].managedObjectContext deleteObject:self];		
}


@end
