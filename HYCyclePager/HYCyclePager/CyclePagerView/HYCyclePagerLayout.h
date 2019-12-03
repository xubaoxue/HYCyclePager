//
//  HYCyclePagerLayout.h
//  HYCyclePager
//
//  Created by 徐保学 on 2019/12/3.
//  Copyright © 2019 徐保学. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HYCyclePagerTransformLayoutType) {
    HYCyclePagerTransformLayoutNormal,
    HYCyclePagerTransformLayoutLinear,
    HYCyclePagerTransformLayoutCoverflow,
};

@class HYCyclePagerLayout;

@protocol HYCyclePagerTransformLayoutDelegate <NSObject>

// initialize layout attributes
- (void)pagerViewTransformLayout:(HYCyclePagerLayout *)pagerViewTransformLayout initializeTransformAttributes:(UICollectionViewLayoutAttributes *)attributes;

// apply layout attributes
- (void)pagerViewTransformLayout:(HYCyclePagerLayout *)pagerViewTransformLayout applyTransformToAttributes:(UICollectionViewLayoutAttributes *)attributes;

@end


@interface HYCyclePagerViewLayout : NSObject

@property (nonatomic, assign) CGSize itemSize;
@property (nonatomic, assign) CGFloat itemSpacing;
@property (nonatomic, assign) UIEdgeInsets sectionInset;

@property (nonatomic, assign) HYCyclePagerTransformLayoutType layoutType;

@property (nonatomic, assign) CGFloat minimumScale; // sacle default 0.8
@property (nonatomic, assign) CGFloat minimumAlpha; // alpha default 1.0
@property (nonatomic, assign) CGFloat maximumAngle; // angle is % default 0.2

@property (nonatomic, assign) BOOL isInfiniteLoop;  // infinte scroll
@property (nonatomic, assign) CGFloat rateOfChange; // scale and angle change rate
@property (nonatomic, assign) BOOL adjustSpacingWhenScroling; 

/**
 pageView cell item vertical centering
 */
@property (nonatomic, assign) BOOL itemVerticalCenter;

/**
 first and last item horizontalc enter, when isInfiniteLoop is NO
 */
@property (nonatomic, assign) BOOL itemHorizontalCenter;

// sectionInset
@property (nonatomic, assign, readonly) UIEdgeInsets onlyOneSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets firstSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets lastSectionInset;
@property (nonatomic, assign, readonly) UIEdgeInsets middleSectionInset;

@end


@interface HYCyclePagerLayout : UICollectionViewFlowLayout

@property (nonatomic, strong) HYCyclePagerViewLayout *layout;

@property (nonatomic, weak, nullable) id<HYCyclePagerTransformLayoutDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
