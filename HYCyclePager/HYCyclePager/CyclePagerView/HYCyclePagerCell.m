//
//  HYCyclePagerCell.m
//  HYCyclePager
//
//  Created by 徐保学 on 2019/12/3.
//  Copyright © 2019 徐保学. All rights reserved.
//

#import "HYCyclePagerCell.h"

@interface HYCyclePagerCell()


@end

@implementation HYCyclePagerCell


- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
        [self.contentView addSubview:self.contentImgV];
        
    }
    return self;
}

#pragma mark ============ lazy

- (UIImageView *)contentImgV
{
    if (_contentImgV == nil) {
        _contentImgV = [[UIImageView alloc] initWithFrame:self.frame];
        _contentImgV.contentMode = UIViewContentModeScaleAspectFill;
    }
    return _contentImgV;
}


@end
