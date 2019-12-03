//
//  HYCyclePageControl.h
//  HYCyclePager
//
//  Created by 徐保学 on 2019/12/3.
//  Copyright © 2019 徐保学. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HYCyclePageControl : UIControl

@property (nonatomic, assign) NSInteger numberOfPages;          // default is 0
@property (nonatomic, assign) NSInteger currentPage;            // default is 0. value pinned to 0..numberOfPages-1

@property (nonatomic, assign) BOOL hidesForSinglePage;          // hide the the indicator if there is only one page. default is NO
@property (nonatomic, assign) BOOL isPageIndicatorBorderWidth;          // hide the the indicator if there is only one page. default is NO
@property (nonatomic, assign) BOOL isCurrentPageIndicatorBorderColor;          // hide the the indicator if there is only one page. default is NO

@property (nonatomic, assign) CGFloat pageIndicatorSpaing;
@property (nonatomic, assign) UIEdgeInsets contentInset; // center will ignore this
@property (nonatomic, assign ,readonly) CGSize contentSize; // real content size

// override super 
//@property (nonatomic, assign) UIControlContentVerticalAlignment contentVerticalAlignment;     // how to position content vertically inside control. default is center
//@property (nonatomic, assign) UIControlContentHorizontalAlignment contentHorizontalAlignment; // how to position content hozontally inside control. default is center


// indicator
@property (nonatomic, assign) CGFloat pageIndicatorBorderWidth;
@property (nonatomic, assign) CGFloat currentPageIndicatorWidth;

@property (nullable, nonatomic,strong) UIColor *pageIndicatorBorderColor;
@property (nullable, nonatomic,strong) UIColor *currentPageIndicatorBorderColor;

// indicatorTint color
@property (nullable, nonatomic,strong) UIColor *pageIndicatorTintColor;
@property (nullable, nonatomic,strong) UIColor *currentPageIndicatorTintColor;

// indicator image
@property (nullable, nonatomic,strong) UIImage *pageIndicatorImage;
@property (nullable, nonatomic,strong) UIImage *currentPageIndicatorImage;


@property (nonatomic, assign) UIViewContentMode indicatorImageContentMode; // default is UIViewContentModeCenter

@property (nonatomic, assign) CGSize pageIndicatorSize; // indicator size
@property (nonatomic, assign) CGSize currentPageIndicatorSize; // default pageIndicatorSize

@property (nonatomic, assign) CGFloat animateDuring; // default 0.3

- (void)setCurrentPage:(NSInteger)currentPage animate:(BOOL)animate;

@end

NS_ASSUME_NONNULL_END
