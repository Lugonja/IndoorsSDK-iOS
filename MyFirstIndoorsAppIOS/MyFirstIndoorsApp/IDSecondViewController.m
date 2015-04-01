//
//  IDSecondViewController.m
//  MyFirstIndoorsApp
//
//  Created by Dominik Hofer on 20/01/15.
//  Copyright (c) 2015 Indoors GmbH. All rights reserved.
//

#import "IDSecondViewController.h"
#import <Indoors/Indoors.h>
#import <Indoors/IndoorsDelegate.h>

@interface IDSecondViewController () <IndoorsLocationListener, IndoorsServiceDelegate, LoadingBuildingDelegate>
//@property (nonatomic, strong) Indoors *indoors;
@end

static Indoors *_indoors;

@implementation IDSecondViewController {
    UILabel *_positionLabel;
    UILabel *_zonesLabel;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];
    
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
    [btn setTitle:@"back" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(buttonClicked) forControlEvents:UIControlEventTouchUpInside];
    btn.center = CGPointMake(100, 100);
    [btn sizeToFit];
    [self.view addSubview:btn];
    
    _positionLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 200, 375, 300)];
    _positionLabel.numberOfLines = 0;
    [self.view addSubview:_positionLabel];
    
    _zonesLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 300, 375, 300)];
    _zonesLabel.numberOfLines = 0;
    _zonesLabel.text = @"No zones";
    [self.view addSubview:_zonesLabel];
    
    if (!_indoors) {
        [self startLocatorWithoutUI];
    }
}

- (void)buttonClicked
{
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)startLocatorWithoutUI
{
    _indoors = [[Indoors alloc] initWithLicenseKey:@"46b30833-2e4a-4038-8fac-8bb8b271880d" andServiceDelegate:self];
    
    [[Indoors instance] registerLocationListener:self];
    
    IDSBuilding* building = [[IDSBuilding alloc] init];
    building.buildingID = 263410748;
    
    [[Indoors instance] setParameterObject:@(3000) forKey:IndoorsParameterKeyGPSBeaconThreshold];
    [[Indoors instance] setParameterObject:@(1) forKey:IndoorsParameterKeyGPSFloorLevel];
    [[Indoors instance] setParameterObject:@(15000) forKey:IndoorsParameterKeyGPSAccuracyThreshold];
    [[Indoors instance] getBuilding:building forRequestDelegate:self];
}

- (void)leftBuilding:(IDSBuilding *)building
{
    NSLog(@"Left building");
}

- (void)changedFloor:(int)floorLevel withName:(NSString *)name
{
    
}

- (void)locationAuthorizationStatusDidChange:(IDSLocationAuthorizationStatus)status
{
    
}

- (void)weakSignal
{
    
}

- (void)positionUpdated:(IDSCoordinate *)userPosition
{
    NSString *positionText = [NSString stringWithFormat:@"\nNO-UI:\nx = %ld\ny = %ld\nz = %ld\na = %ld", (long)userPosition.x, (long)userPosition.y, (long)userPosition.z, (long)userPosition.accuracy];
    
    NSLog(positionText);
    _positionLabel.text = positionText;
}

- (void)zonesEntered:(NSArray *)zones
{
    _zonesLabel.text = [zones description];
}

@end
