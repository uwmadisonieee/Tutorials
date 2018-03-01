# Android 101 Workshop Guide

## What you need
- [Android Studio](https://developer.android.com/studio/index.html)
- An Android mobile device
- A USB cable to connect your Android device to your computer

## Getting Started
1. Open Android Studio on computer
2. Create a new project
   1. `File->New->New Project`
   2. Application Name: `AndroidDemoIEEE`
   3. Company Domain: `<INSERT_NAME_HERE>.com`
	   1. Doesn’t have to be a valid domain, just used by Google Play Store if published
   4. Choose project location
   5. Hit `Next`
   6. We will be building our app for phones and tablets, so default settings are fine
   7. Hit `Next`
   8. Select `Empty Activity`, we will be creating everything ourselves
   9. Hit `Next`
   10. Leave Activity Name as `MainActivity`
	   1. This is the default activity that will be launched on startup
	   2. By  common naming conventions, this is usually called `MainActivity`
   11. Leave other settings as is, notice how Layout Name is a flipped version of Activity Name
   12. This is usually done to distinguish Activities from Layouts
   13. Hit `Finish`
3. Use project navigation drawer on left side to open `activity_main.xml`.
   1. Make sure you have **Project** tab selected on side as well as **Android** tab selected on top
   2. Locate `res/layout` folder
   3. Find `activity_main.xml` and double click to open
4. Add some basic components
   1. Locate the **Design** and **Text** tabs on the bottom of the editor window
   2. Click the **Design** tab
   3. Double click the `“Hello World”` component
	   1. Set the **text** field to `“This is Activity One!”`
	   2. Since we won’t be manipulating the text through Java, we won’t need the ID
   4. Under the **Widgets** section, locate a **Button**
   5. Click and drag a Button to the screen
   6. Double click the Button to set fields
	   1. Set **text** field to `“Move to Activity Two”`
	   2. Set **id** field to `“button_move1”`
		   1. Note: Unlike the Hello World component, we need this component’s ID since we will be adding a listener to it in Java
	7. Open `MainActivity.java` using same method as in #3
		1. `MainActivity.java` is located in `java/<YOUR_DOMAIN_NAME>` folder
5. Add a listener to your Button
   1. Use the **findViewById** method to get a reference to your button
	  1. `Button myButton = (Button)findViewById(R.id.button_move);`
   2. Use the **setOnCLickListener** method to add a listener callback function to your button

	```
	myButton.setOnClickListener(new View.OnClickListener() {
		@Override
		public void onClick(View view) {
			// Code when clicked
		}
	});
	```

6. Create your second Activity
   1. In your navigation drawer, right click app and select `New->Activity->Empty Activity`
   2. Set **Activity Name** to `“SecondActivity”`
   3. The **Layout Name** should automatically change to `“activity_second”`, so leave it as is
   4. Leave all other fields as default
   5. Hit `Finish`
7. Add a new button to your new Activity, but this time using xml
   1. Between the `“RelativeLayout”` tags, insert this code
	```
	<Button
		android:layout_width="wrap_content"
		android:layout_height="wrap_content"
		android:text="Move to Activity One"
		android:id="@+id/button_move2"
		android:layout_alignParentTop="true" />
	```
	2. Look through the properties we set and see if you can find what our new button’s ID is
		1. Hint: All IDs are preceded with **@+id/**, this is not part of the ID itself
8. Add a listener in `SecondActivity.java`’s `onCreate()` method just like in step 5
   1. **Hint:** Make sure you grab the button with the right ID (button_move2)
9. Add Intents to each Button listener
   1. In `MainActivity.java`, create a function `switchActivities()` that will be called inside your `onClick()` method
   2. Inside the `switchActivities()` function, build an intent to move to SecondActivity
   ```
   Intent newIntent = new Intent(this, SecondActivity.class);
   startActivity(newIntent);
   ```
	3. Add a call to `switchActivites()` in your `onClick()` method
		1. **Note:** The reason we couldn’t build the Intent inside the `onClick()` method is that the first parameter of the Intent constructor takes a **“Context”** object, which cannot be accessed from within callback functions
	4. In `SecondActivity.java`, do the same procedure, but when building the Intent be sure to move to the right Activity (MainActivity)
	```
	Intent newIntent = new Intent(this, MainActivity.class);
	startActivity(newIntent);
	```
10. Add a bit of color to each Activity
	1. Open `colors.xml` located in the `res/values` folder
	2. Add two colors to your selection
	```
	<color name="tunnelBobBlue">#0000f0</color>
	<color name="makerspaceMaroon">#f00000</color>
	```
	3. Back in your `activity_main.xml` file in **Text** mode, add this line in the opening tag of RelativeLayout to make the background colorful
	```
	<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
  		xmlns:tools="http://schemas.android.com/tools"
  		android:background="@color/tunnelBobBlue"
   		android:layout_width="match_parent"
	```
	4. Do the same in `activity_second.xml` but with makerspaceMaroon
	5. You should now be able to see your colors in **Design** mode in your xml files!
11. Enabling your phone for testing your app
	1. **Notes:**
		1. If you don’t have an Android phone, you can borrow one of ours
		2. You could also set up an emulator but that would take some time
	2. On your phone, go to `Settings->About` Phone
	3. Tap **Build Number** 7 times and you’ll be an official Android developer!
	4. Once enabled, you’ll see a new settings category called “Developer Options”
	5. In Developer Options, enable USB Debugging
	6. Plug your phone into your computer
	7. In Android Studio, hit the ![play button](play_button.png) button
	8. Select your device, and hit **OK**
		1. Note: The first build might take a while, but be patient!
	9. Play with moving back and forth between your activities


