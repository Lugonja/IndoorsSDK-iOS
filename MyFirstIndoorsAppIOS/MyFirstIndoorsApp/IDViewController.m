//
//  IDViewController.m
//  MyFirstIndoorsApp
//
//  Copyright (c) 2013 indoo.rs GmbH. All rights reserved.
//

#import "IDViewController.h"
#import <Indoors/IndoorsBuilder.h>
#import <IndoorsSurface/IndoorsSurfaceBuilder.h>

@interface IDViewController () <IndoorsLocationListener, IndoorsServiceDelegate, LoadingBuildingDelegate>

@end

@implementation IDViewController {
    IndoorsSurfaceBuilder *_surfaceBuilder;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    IndoorsBuilder *builder = [[IndoorsBuilder alloc] init];
    
    // TODO: replace with your API-key
    [builder setApiKey:@"YOUR-API-KEY"];
    // TODO: replace with your building ID
    [builder setBuildingId:123456789];
    [builder enableEvaluationMode:NO];
    
    _surfaceBuilder = [[IndoorsSurfaceBuilder alloc] initWithIndoorsBuilder:builder inView:self.view];
    
    [_surfaceBuilder registerForSurfaceServiceUpdates:self];
    [_surfaceBuilder registerForSurfaceLocationUpdates:self];
    
    [_surfaceBuilder setZoneDisplayMode:IndoorsSurfaceZoneDisplayModeUserCurrentLocation];
    [_surfaceBuilder setUserPositionDisplayMode:IndoorsSurfaceUserPositionDisplayModeDefault];
    
    [_surfaceBuilder build];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - IndoorsLocationListener, IndoorsServiceDelegate, LoadingBuildingDelegate

- (void)connected
{
}

- (void)locationAuthorizationStatusDidChange:(IDSLocationAuthorizationStatus)status
{
    NSLog(@"locationAuthorizationStatusDidChange");
}

- (void)bluetoothStateDidChange:(IDSBluetoothState)bluetoothState
{
    NSLog(@"bluetoothStateDidChange");
}

- (void)onError:(IndoorsError *)indoorsError
{
}

- (void)loadingBuilding:(NSNumber *)progress
{
    NSLog(@"loading building progress: %d", [progress intValue]);
}

- (void)buildingLoaded:(IDSBuilding *)building
{
    NSLog(@"building loaded");
}

- (void)loadingBuildingFailed
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Failed to load building" delegate:Nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

- (void)changedFloor:(int)floorLevel withName:(NSString *)name
{
    NSLog(@"changed floor: %d", floorLevel);
}

- (void)positionUpdated:(IDSCoordinate *)userPosition
{
    NSLog(@"userPosition: x=%ld, y = %ld, z = %ld", (long)userPosition.x, (long)userPosition.y, (long)userPosition.z);
}

- (void)orientationUpdated:(float)orientation
{
    NSLog(@"orientation: %f", orientation);
}

- (void)zonesEntered:(NSArray *)zones
{
    NSLog(@"zones entered: %@", zones);
}

- (void)weakSignal
{
    NSLog(@"weak signal");
}

- (void)contextUpdated:(IDSContext *)context
{
    NSLog(@"contextUpdated");
}

@end
