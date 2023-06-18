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
void enableButtons(); //enables all buttons and sliders after loading an image
```
To save the adjusted file we generally use `SaveFile()` function which saves the file at given path.

## Accurate adjustments of gamma correction, brightness and contrast for a selected image region
To start with, every time the slider is moved, the function ```void AdjustColors(double brightness, double contrast, double gamma)``` is executed.
This function uses the 
```
void AdjustColorsForBitmap(FIBITMAP* bitmap, double brightness, double contrast, double gamma, bool applyRed, bool applyGreen, bool applyBlue, bool applyDark, bool applyMedium, bool applyBright, double brightnessLevels[2])
```
method on a copy of the whole image. In this method we basically use the `FreeImage_AdjustColors()` function which precisely adjusts the parameters of the input bitmap or function writed by us: 
```
void adjustColorsBrightnessRange(FIBITMAP* bitmap, std::function<bool(double, double, double)> f, double firstLimit, double secondLimit)
```
This function iterates over pixels and applies changes when passed function f is true.   
To sum up, everything boils down to using the `FreeImage_AdjustColors()` function from the FreeImage library.

## Ability to make adjustments for the RGB channels collectively as well as individually
In our GUI, there is a corresponding checkbox for each RGB channel. 
The `AdjustColorsForBitmap()` function checks how many checkboxes are selected to optimize this operation and perform maximum one iteration over pixels adjusting factors.  
- If all checkboxes are selected, we adjust colors for the whole image.  
- If two checkboxes are selected, we save the channel that should not be changed, apply changes on two other channels, and copy the saved channel to output image.  
- If one checkbox is selected, then we adjust colors only on the corresponding channel and copy it to the output image.  

## Ability to make adjustments for bright, medium and dark colors
Just like with colors, in our GUI, there are corresponding checkboxes for rach brightness level.
In `AdjustColorsForBitmap()`, depending on the selected brightness levels, we set the boundaries for the intervals in which changes should be made.  
Then, we use the `adjustColorsBrightnessRange()` method. Its operation consists of adjusting colors for the copy of input bitmap and then copying the pixels that fulfill the function f to the original bitmap.

## Real-time observation of the results
At this point, there isn't much to explain. The program is optimized in such a way that the on-screen changes occur smoothly.

## Histogram of both the selected region and the entire image
To draw the Histogram, we wrote the `void drawHistogram(FIBITMAP *bitmap)` function which is executed in `AdjustColors()`. It uses the method from FreeImage library - `FreeImage_GetHistogram()` which sets the height of rectangles in array. Then we draw all rectangles at the bottom panel.  
If you click on the "Histogram for the entire photo" button, `drawHistogram()` input is the bitmap from the whole image and the proper histogram is drawn in the panel.
