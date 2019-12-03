//
//  HYCyclePagerView.h
//  HYCyclePager
//
//  Created by 徐保学 on 2019/12/3.
//  Copyright © 2019 徐保学. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "HYCyclePagerLayout.h"

NS_ASSUME_NONNULL_BEGIN

typedef struct {
    NSInteger index;
    NSInteger section;
}HYIndexSection;

// pagerView scrolling direction
typedef NS_ENUM(NSUInteger, HYPagerScrollDirection) {
    HYPagerScrollDirectionLeft,
    HYPagerScrollDirectionRight,
};

@class HYCyclePagerView;
@protocol HYCyclePagerViewDataSource <NSObject>

- (NSInteger)numberOfItemsInPagerView:(HYCyclePagerView *)pageView;

- (__kindof UICollectionViewCell *)pagerView:(HYCyclePagerView *)pagerView cellForItemAtIndex:(NSInteger)index;

/**
 return pagerView layout,and cache layout
 */
- (HYCyclePagerViewLayout *)layoutForPagerView:(HYCyclePagerView *)pageView;

@end

@protocol HYCyclePagerViewDelegate <NSObject>

@optional

/**
 pagerView did scroll to new index page
 */
- (void)pagerView:(HYCyclePagerView *)pageView didScrollFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/**
 pagerView did selected item cell
 */
- (void)pagerView:(HYCyclePagerView *)pageView didSelectedItemCell:(__kindof UICollectionViewCell *)cell atIndex:(NSInteger)index;
- (void)pagerView:(HYCyclePagerView *)pageView didSelectedItemCell:(__kindof UICollectionViewCell *)cell atIndexSection:(HYIndexSection)indexSection;

// custom layout
- (void)pagerView:(HYCyclePagerView *)pageView initializeTransformAttributes:(UICollectionViewLayoutAttributes *)attributes;

- (void)pagerView:(HYCyclePagerView *)pageView applyTransformToAttributes:(UICollectionViewLayoutAttributes *)attributes;


// scrollViewDelegate

- (void)pagerViewDidScroll:(HYCyclePagerView *)pageView;

- (void)pagerViewWillBeginDragging:(HYCyclePagerView *)pageView;

- (void)pagerViewDidEndDragging:(HYCyclePagerView *)pageView willDecelerate:(BOOL)decelerate;

- (void)pagerViewWillBeginDecelerating:(HYCyclePagerView *)pageView;

- (void)pagerViewDidEndDecelerating:(HYCyclePagerView *)pageView;

- (void)pagerViewWillBeginScrollingAnimation:(HYCyclePagerView *)pageView;

- (void)pagerViewDidEndScrollingAnimation:(HYCyclePagerView *)pageView;

@end


@interface HYCyclePagerView : UIView

// will be automatically resized to track the size of the pagerView
@property (nonatomic, strong, nullable) UIView *backgroundView; 

@property (nonatomic, weak, nullable) id<HYCyclePagerViewDataSource> dataSource;
@property (nonatomic, weak, nullable) id<HYCyclePagerViewDelegate> delegate;

// pager view, don't set dataSource and delegate
@property (nonatomic, weak, readonly) UICollectionView *collectionView;
// pager view layout
@property (nonatomic, strong, readonly) HYCyclePagerViewLayout *layout;

/**
 is infinite cycle pageview
 */
@property (nonatomic, assign) BOOL isInfiniteLoop;

/**
 pagerView automatic scroll time interval, default 0,disable automatic
 */
@property (nonatomic, assign) CGFloat autoScrollInterval;

@property (nonatomic, assign) BOOL reloadDataNeedResetIndex;

/**
 current page index
 */
@property (nonatomic, assign, readonly) NSInteger curIndex;
@property (nonatomic, assign, readonly) HYIndexSection indexSection;

// scrollView property
@property (nonatomic, assign, readonly) CGPoint contentOffset;
@property (nonatomic, assign, readonly) BOOL tracking;
@property (nonatomic, assign, readonly) BOOL dragging;
@property (nonatomic, assign, readonly) BOOL decelerating;


/**
 reload data, !!important!!: will clear layout and call delegate layoutForPagerView
 */
- (void)reloadData;

/**
 update data is reload data, but not clear layuot
 */
- (void)updateData;

/**
 if you only want update layout
 */
- (void)setNeedUpdateLayout;

/**
 will set layout nil and call delegate->layoutForPagerView
 */
- (void)setNeedClearLayout;

/**
 current index cell in pagerView
 */
- (__kindof UICollectionViewCell * _Nullable)curIndexCell;

/**
 visible cells in pageView
 */
- (NSArray<__kindof UICollectionViewCell *> *_Nullable)visibleCells;


/**
 visible pageView indexs, maybe repeat index
 */
- (NSArray *)visibleIndexs;

/**
 scroll to item at index
 */
- (void)scrollToItemAtIndex:(NSInteger)index animate:(BOOL)animate;
- (void)scrollToItemAtIndexSection:(HYIndexSection)indexSection animate:(BOOL)animate;
/**
 scroll to next or pre item
 */
- (void)scrollToNearlyIndexAtDirection:(HYPagerScrollDirection)direction animate:(BOOL)animate;

/**
 register pager view cell with class
 */
- (void)registerClass:(Class)Class forCellWithReuseIdentifier:(NSString *)identifier;

/**
 register pager view cell with nib
 */
- (void)registerNib:(UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;

/**
 dequeue reusable cell for pagerView
 */
- (__kindof UICollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndex:(NSInteger)index;

@end

NS_ASSUME_NONNULL_END
