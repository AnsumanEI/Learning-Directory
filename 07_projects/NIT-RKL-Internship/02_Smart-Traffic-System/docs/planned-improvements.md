First Modification: Vehicle Count Rate Adjustment

Add a slider or button to adjust the vehicle count decrement rate.
Decrease vehicle count by 1 every 400 ms during green light and every 700 ms during yellow light.
Second Modification: Round Timer Element

Create a round CSS element with transparency and hover effects to display a countdown timer for each light at every post.
Third Modification: No Post Repetition

Ensure that no traffic post is repeated twice in the signal sequence.
If a post crosses the threshold value, either skip it or delay the green signal until the vehicle count decreases below the threshold.
Fourth Modification: Control Menu and Performance Optimization

Create a menu to control variables such as vehicle count rate, green/yellow light durations, and threshold value.
Improve website performance to reduce lag and ensure it works in real-time without delays, even beyond localhost.