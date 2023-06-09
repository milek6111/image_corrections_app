# Documentation
> Short explanation and implementation of our features

## Loading/Saving JPEG and PNG files
To load our file, we use `LoadFile()` function from wxWidgets which takes the path to the file as an argument.
After that, we use a bunch of functions such as:
```
void setBrightnessLimits(FIBITMAP* bitmap); //find maximum and minimum value of brightness of image and calculate rages which are use in brightness checkboxes
void prepareScaledThumbnail(); //sets image proportion for proper scrolling and adjusts scrollbars to new panel size
void afterScroll(); //used to set fragment position after moving red rectangle
void displayMainImage(); //displays main image
void enableButtons(); //enables all buttons and slider after loading an image
```
To save the adjusted file we generally use `SaveFile()` function which saves the file at given path.

## Accurate adjustments of gamma correction, brightness and contrast for a selected image region

## Ability to make adjustments for the RGB channels collectively as well as individually

## Ability to make adjustments for bright, medium and dark colors

## Real-time observation of the results

## Histogram of both the selected region and the entire image
