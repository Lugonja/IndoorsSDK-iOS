//
//  IDViewController.m
//  MyFirstIndoorsApp
//
//  Copyright (c) 2013 indoo.rs GmbH. All rights reserved.
//

#import "IDViewController.h"
#import <Indoors/IndoorsBuilder.h>
#import <IndoorsSurface/IndoorsSurfaceBuilder.h>
#import <IndoorsSurface/IndoorsSurfaceDelegates.h>
#import <Indoors/Indoors.h>
#import <Indoors/IndoorsDelegate.h>
#import "IDSecondViewController.h"
#import "IDLocationListener.h"

@interface IDViewController () <IndoorsSurfaceLocationDelegate, IndoorsSurfaceServiceDelegate, IndoorsLocationListener>
@property (nonatomic, strong) IndoorsSurfaceBuilder* surfaceBuilder;
@property (nonatomic, strong) Indoors *indoors;
@end

@implementation IDViewController {
    UIView *_surfaceContainer;
    UILabel *_positionLabel;
    UILabel *_zonesLabel;
    IDSecondViewController *_vc;
    ISIndoorsSurface *_surface;
    IDLocationListener *_listener;
}

@synthesize surfaceBuilder;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _surfaceContainer = [[UIView alloc] initWithFrame:self.view.frame];
    [self.view addSubview:_surfaceContainer];
    
    [self.view addSubview:({
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
        [btn setTitle:@"start surface locator (GPS enabled)" forState:UIControlStateNormal];
        [btn addTarget:self action:@selector(addSurface) forControlEvents:UIControlEventTouchUpInside];
        btn.center = CGPointMake(100, 200);
        [btn sizeToFit];
        btn;
    })];
    
    [self.view addSubview:({
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
        [btn setTitle:@"start no-UI locator (GPS disabled)" forState:UIControlStateNormal];
        [btn addTarget:self action:@selector(buttonClicked) forControlEvents:UIControlEventTouchUpInside];
        btn.center = CGPointMake(100, 100);
        [btn sizeToFit];
        btn;
    })];
    
    [self.view addSubview:({
        UIButton *btn = [UIButton buttonWithType:UIButtonTypeSystem];
        [btn setTitle:@"switch" forState:UIControlStateNormal];
        [btn addTarget:self action:@selector(switchFloor) forControlEvents:UIControlEventTouchUpInside];
        btn.center = CGPointMake(100, 300);
        [btn sizeToFit];
        btn;
    })];
    
    _positionLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 200, 375, 300)];
    _positionLabel.numberOfLines = 0;
    [self.view addSubview:_positionLabel];
    
    _zonesLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 300, 375, 300)];
    _zonesLabel.numberOfLines = 0;
    _zonesLabel.text = @"No zones";
    [self.view addSubview:_zonesLabel];
    
    _vc = [[IDSecondViewController alloc] init];
}

- (void)buttonClicked
{
    [self presentViewController:_vc animated:YES completion:nil];
}

- (void)switchFloor
{
    static BOOL toggle = YES;
    
    if (toggle) {
        [_surface setFloorLevel:0];
//        _surface.enableAutomaticFloorSelection = NO;
        toggle = NO;
    } else {
        [_surface setFloorLevel:1];
//        _surface.enableAutomaticFloorSelection = NO;
        toggle = YES;
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)addSurface
{
    IndoorsBuilder* builder = [[IndoorsBuilder alloc] init];
    
    // Ind: 46b30833-2e4a-4038-8fac-8bb8b271880d
    // Aaa: @"cefca17d-871d-4498-a1eb-499cf4968a6f"
    [builder setApiKey:@"46b30833-2e4a-4038-8fac-8bb8b271880d"];

    // Ind: 259067724
    // Aaa: 263410748
    // Aaa: 263924543 (22.1.)
    [builder setBuildingId:259067724]; // 128718481, 259067724, 245000088, 128718481
    [builder enableEvaluationMode:NO];
    
    surfaceBuilder = [[IndoorsSurfaceBuilder alloc] initWithIndoorsBuilder:builder inView:_surfaceContainer];
    
    [surfaceBuilder registerForSurfaceServiceUpdates:self];
    
    [surfaceBuilder setZoneDisplayMode:IndoorsSurfaceZoneDisplayModeUserCurrentLocation];
    [surfaceBuilder setUserPositionDisplayMode:IndoorsSurfaceUserPositionDisplayModeDefault];
    
    [surfaceBuilder build];
    
    [[Indoors instance] setParameterObject:@(99999) forKey:IndoorsParameterKeyGPSBeaconThreshold];
    [[Indoors instance] setParameterObject:@(0) forKey:IndoorsParameterKeyGPSFloorLevel];
    [[Indoors instance] setParameterObject:@(9000) forKey:IndoorsParameterKeyGPSAccuracyThreshold];
    
    _surface = surfaceBuilder.indoorsSurface;
    _surface.enableAutomaticFloorSelection = YES;
    
    [self addSecondListener];
}

- (void)addSecondListener
{
    _listener = [[IDLocationListener alloc] init];
    [[Indoors instance] registerLocationListener:_listener];
}

#pragma mark - Service Delegate
- (void)connected
{
    [surfaceBuilder registerForSurfaceLocationUpdates:self];
}

- (void)onError:(IndoorsError*) indoorsError
{
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Failed to authenticate with your API key" delegate:Nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

- (void)loadingBuilding:(NSNumber*)progress
{
}

- (void)buildingLoaded:(IDSBuilding*)building
{
//    surfaceBuilder.indoorsSurface.enableAutomaticFloorSelection = NO;
//    [_surface setFloorLevel:1];
}

- (void)loadingBuildingFailed
{
    UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Failed to load building" delegate:Nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

#pragma mark - IndoorsSurfaceLocationManagerDelegate
- (void)updateFloorLevel:(int)floorLevel name:(NSString*)name
{
    ;
}

- (void)updateUserPosition:(IDSCoordinate*)userPosition
{
    NSString *positionText = [NSString stringWithFormat:@"\nSURFACE:\nx=%ld\ny = %ld\nz = %ld\nacc = %ld", (long)userPosition.x, (long)userPosition.y, (long)userPosition.z, (long)userPosition.accuracy];
    
    NSLog(positionText);
    _positionLabel.text = positionText;
}

- (void)updateUserOrientation:(float)orientation
{
}

- (void)weakSignal
{
}

- (void)zonesEntered:(NSArray *)zones
{
    _zonesLabel.text = [zones description];
}

@end
