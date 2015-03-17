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

@interface IDViewController () <IndoorsSurfaceLocationDelegate, IndoorsSurfaceServiceDelegate>
@property (nonatomic, strong) IndoorsSurfaceBuilder *surfaceBuilder;
@end

@implementation IDViewController
@synthesize surfaceBuilder;

- (void)viewDidLoad
{
    [super viewDidLoad];

    IndoorsBuilder *builder = [[IndoorsBuilder alloc] init];
    
    NSString *apiKey = @"YOUR-API-KEY"; // TODO: replace with your API-key
    NSInteger buildingId = 123456789; // TODO: replace with your building ID
    
    if (buildingId == 123456789 || [apiKey isEqualToString:@"YOUR-API-KEY"] || [apiKey isEqualToString:@""]) {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error"
                                                        message:@"Please set your API-Key and your buildingID. You can find this information on my.indoo.rs!"
                                                       delegate:nil cancelButtonTitle:@"Ok"
                                              otherButtonTitles:nil, nil];
        [alert show];
        return;
    }
    
    [builder setApiKey:apiKey];
    [builder setBuildingId:buildingId];
    
    [builder enableEvaluationMode:NO];
    
    surfaceBuilder = [[IndoorsSurfaceBuilder alloc] initWithIndoorsBuilder:builder inView:self.view];
    
    [surfaceBuilder registerForSurfaceServiceUpdates:self];
    
    [surfaceBuilder setZoneDisplayMode:IndoorsSurfaceZoneDisplayModeUserCurrentLocation];
    [surfaceBuilder setUserPositionDisplayMode:IndoorsSurfaceUserPositionDisplayModeDefault];
    
    [surfaceBuilder build];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - Service Delegate

- (void)connected
{
    [surfaceBuilder registerForSurfaceLocationUpdates:self];
}

- (void)onError:(IndoorsError *)indoorsError
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Failed to authenticate with your API key" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
}

- (void)loadingBuilding:(NSNumber *)progress
{
}

- (void)buildingLoaded:(IDSBuilding *)building
{
}

- (void)loadingBuildingFailed
{
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Failed to load building" delegate:Nil cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
        [alert show];
}

#pragma mark - IndoorsSurfaceLocationManagerDelegate

- (void)updateFloorLevel:(int)floorLevel name:(NSString *)name
{
}

- (void)updateUserPosition:(IDSCoordinate *)userPosition
{
}

- (void)updateUserOrientation:(float)orientation
{
}

- (void)weakSignal
{
}

@end
