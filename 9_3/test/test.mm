#include "Header.h"
#import <XCTest/XCTest.h>

@interface teest : XCTestCase

@end

@implementation teest

- (void)testLab {
    
    Tovari* s = new Tovari;
    s->nazva = "apelsin";
    s->magazin = ATB;
    s->vartist = 5;
    s->kilk = 10;
    s->odvim = "pak";
    
    Search(s, 1);
    
    XCTAssertEqual(-1, -1);
    
}


@end
