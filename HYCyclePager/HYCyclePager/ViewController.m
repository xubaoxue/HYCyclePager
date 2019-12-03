//
//  ViewController.m
//  HYCyclePager
//
//  Created by 徐保学 on 2019/12/3.
//  Copyright © 2019 徐保学. All rights reserved.
//

#import "ViewController.h"
#import "HYCyclePagerLayout.h"
#import "HYCyclePagerView.h"
#import "HYCyclePagerCell.h"
#import "HYCyclePageControl.h"

#define rgba(r, g, b, a)    [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define kScreenHeight       [UIScreen mainScreen].bounds.size.height
#define kScreenWidth        [UIScreen mainScreen].bounds.size.width

@interface ViewController ()<HYCyclePagerViewDataSource, HYCyclePagerViewDelegate>

@property (nonatomic, strong) HYCyclePagerView   *pagerView;
@property (nonatomic, strong) HYCyclePageControl *pageControl;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self addPagerView];
    [self addPageControl];
}

#pragma mark ========== HYCyclePagerView
- (void)addPagerView
{
    HYCyclePagerView *pagerView = [[HYCyclePagerView alloc] initWithFrame:CGRectMake(0, 4, kScreenWidth - 28, 144)];
    pagerView.isInfiniteLoop = YES;
    pagerView.autoScrollInterval = 2.0;
    pagerView.dataSource = self;
    pagerView.delegate = self;
    [pagerView registerClass:[HYCyclePagerCell class] forCellWithReuseIdentifier:@"cellId"];
    
    [self.view addSubview:pagerView];
    _pagerView = pagerView;
}

- (void)addPageControl
{
    HYCyclePageControl *pageControl = [[HYCyclePageControl alloc] initWithFrame:CGRectMake(0, CGRectGetHeight(_pagerView.frame) - 26, CGRectGetWidth(_pagerView.frame), 26)];
    pageControl.numberOfPages = 5;
    pageControl.currentPageIndicatorSize = CGSizeMake(6, 6);
    pageControl.pageIndicatorSize = CGSizeMake(6, 6);
    pageControl.currentPageIndicatorTintColor = rgba(255,62,41,1);
    pageControl.pageIndicatorTintColor = [UIColor clearColor];
    pageControl.isPageIndicatorBorderWidth = YES;
    pageControl.isCurrentPageIndicatorBorderColor = 1;
    pageControl.pageIndicatorBorderWidth = 1;
    pageControl.pageIndicatorBorderColor = rgba(255,255,255,1);
    [_pagerView addSubview:pageControl];
    _pageControl = pageControl;
}


#pragma mark ========== HYCyclePagerViewDataSource
- (NSInteger)numberOfItemsInPagerView:(HYCyclePagerView *)pageView
{
    return 5;
}

- (UICollectionViewCell *)pagerView:(HYCyclePagerView *)pagerView cellForItemAtIndex:(NSInteger)index
{
    HYCyclePagerCell *cell = [pagerView dequeueReusableCellWithReuseIdentifier:@"cellId" forIndex:index];
    
    cell.contentImgV.image = [UIImage imageNamed:@"tupian1"];
    
    return cell;
}

- (HYCyclePagerViewLayout *)layoutForPagerView:(HYCyclePagerView *)pageView
{
    HYCyclePagerViewLayout *layout = [[HYCyclePagerViewLayout alloc]init];
    layout.itemSize = CGSizeMake(kScreenWidth - 28, 144);
    layout.itemSpacing = 0;
    layout.itemHorizontalCenter = YES;
    
    return layout;
}

- (void)pagerView:(HYCyclePagerView *)pageView didScrollFromIndex:(NSInteger)fromIndex toIndex:(NSInteger)toIndex
{
    _pageControl.currentPage = toIndex;
    //[_pageControl setCurrentPage:newIndex animate:YES];
//    NSLog(@"%ld ->  %ld",(long)fromIndex,(long)toIndex);
}
- (void)pagerView:(HYCyclePagerView *)pageView didSelectedItemCell:(__kindof UICollectionViewCell *)cell atIndex:(NSInteger)index
{
    NSLog(@"点击的角标 ----- %zd",index);
}



@end
