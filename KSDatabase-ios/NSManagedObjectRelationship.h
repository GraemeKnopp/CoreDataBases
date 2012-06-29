
#define ADD_RELATIONSHIP(CLASS, PROPERTY) \
- (void)insertObject:(CLASS *)value in##PROPERTY##AtIndex:(NSUInteger)idx { \
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:idx];\
    [self willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet insertObject:value atIndex:idx];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)removeObjectFrom##PROPERTY##AtIndex:(NSUInteger)idx {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:idx];\
    [self willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet removeObjectAtIndex:idx];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)insert##PROPERTY:(NSArray *)values atIndexes:(NSIndexSet *)indexes {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    [self willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet insertObjects:values atIndexes:indexes];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)remove##PROPERTY##AtIndexes:(NSIndexSet *)indexes {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    [self willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet removeObjectsAtIndexes:indexes];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)replaceObjectIn##PROPERTY##AtIndex:(NSUInteger)idx withObject:(CLASS *)value {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:idx];\
    [self willChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet replaceObjectAtIndex:idx withObject:value];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)replace##PROPERTY##AtIndexes:(NSIndexSet *)indexes with##PROPERTY:(NSArray *)values {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    [self willChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:property];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    [tmpOrderedSet replaceObjectsAtIndexes:indexes withObjects:values];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)add##PROPERTY##Object:(CLASS *)value {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    NSUInteger idx = [tmpOrderedSet count];\
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:idx];\
    [self willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
    [tmpOrderedSet addObject:value];\
    [self setPrimitiveValue:tmpOrderedSet forKey:property];\
    [self didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
}\
\
- (void)remove##PROPERTY##Object:(CLASS *)value {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    NSUInteger idx = [tmpOrderedSet indexOfObject:value];\
    if (idx != NSNotFound) {\
        NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:idx];\
        [self willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
        [tmpOrderedSet removeObject:value];\
        [self setPrimitiveValue:tmpOrderedSet forKey:property];\
        [self didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
    }\
}\
\
- (void)add##PROPERTY:(NSOrderedSet *)values {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    NSMutableIndexSet *indexes = [NSMutableIndexSet indexSet];\
    NSUInteger valuesCount = [values count];\
    NSUInteger objectsCount = [tmpOrderedSet count];\
    for (NSUInteger i = 0; i < valuesCount; ++i) {\
        [indexes addIndex:(objectsCount + i)];\
    }\
    if (valuesCount > 0) {\
        [self willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
        [tmpOrderedSet addObjectsFromArray:[values array]];\
        [self setPrimitiveValue:tmpOrderedSet forKey:property];\
        [self didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:property];\
    }\
}\
\
- (void)remove##PROPERTY:(NSOrderedSet *)values {\
	NSString* property = [@""#PROPERTY stringByReplacingCharactersInRange:NSMakeRange(0,1) withString:[[@""#PROPERTY substringToIndex:1] lowercaseString]];\
    NSMutableOrderedSet *tmpOrderedSet = [NSMutableOrderedSet orderedSetWithOrderedSet:[self mutableOrderedSetValueForKey:property]];\
    NSMutableIndexSet *indexes = [NSMutableIndexSet indexSet];\
    for (id value in values) {\
        NSUInteger idx = [tmpOrderedSet indexOfObject:value];\
        if (idx != NSNotFound) {\
            [indexes addIndex:idx];\
        }\
    }\
    if ([indexes count] > 0) {\
        [self willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
        [tmpOrderedSet removeObjectsAtIndexes:indexes];\
        [self setPrimitiveValue:tmpOrderedSet forKey:property];\
        [self didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:property];\
    }\
}\
