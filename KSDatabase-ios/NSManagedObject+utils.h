//
//  NSManagedObject+utils.h
//  QuestionEditor
//
//  Created by Graeme Knopp on 12-06-29.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <CoreData/CoreData.h>

@interface NSManagedObject (utils)

+(id) create;
+(id) createFromDictionary:(NSDictionary*)info;

+(NSMutableArray*) fetch:(NSString *)predicate;
+(NSMutableArray*) fetch:(NSString *)predicate orderBy:(NSString*)field;


-(NSDictionary*) dictionaryInfo;
-(void) remove;

@end
