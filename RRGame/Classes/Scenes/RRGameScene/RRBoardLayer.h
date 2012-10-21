//
//  RRBoardLayer.h
//  RRHeredox
//
//  Created by Rolandas Razma on 7/14/12.
//
//  Copyright (c) 2012 Rolandas Razma <rolandas@razma.lt>
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#import "UDLayer.h"

@class RRTile;
@protocol RRBoardLayerDelegate;


@interface RRBoardLayer : UDLayer {
    id<RRBoardLayerDelegate>_delegate;
    
    RRGameMode          _gameMode;
    
    uint                _symbolsBlack;
    uint                _symbolsWhite;
    
    CGPoint             _activeTileLastPosition;
    
    RRTile              *_activeTile;
    CGPoint             _activeTileTouchOffset;
    BOOL                _activeTileMoved;
    
    CGRect              _gridBounds;
    RRTile              *_emptyTile;
}

@property (nonatomic, readonly) RRTile *activeTile;
@property (nonatomic, readonly) uint symbolsBlack;
@property (nonatomic, readonly) uint symbolsWhite;
@property (nonatomic, readonly) CGRect gridBounds;
@property (nonatomic, assign)   id <RRBoardLayerDelegate>delegate;

- (id)initWithGameMode:(RRGameMode)gameMode;

- (void)addTile:(RRTile *)tile animated:(BOOL)animated;
- (BOOL)haltTilePlaces;
- (BOOL)canPlaceTileAtGridLocation:(CGPoint)gridLocation;
- (void)countSymbolsAtTile:(RRTile *)tile white:(NSUInteger *)white black:(NSUInteger *)black;
- (RRTile *)tileAtGridPosition:(CGPoint)gridPosition;
- (void)resetBoardForGameMode:(RRGameMode)gameMode;

@end


@protocol RRBoardLayerDelegate <NSObject>

- (void)boardLayer:(RRBoardLayer *)gameBoardLayer movedActiveTile:(RRTileMove)tileMove;

@end