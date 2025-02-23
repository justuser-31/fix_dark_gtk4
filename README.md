# HOW TO USE
Just include `fix_dark.h` in your app's activate function and add `fix_dark();`

Like this:
```c
...
#include "fix_dark.h"
...
static void activate(GtkApplication* app, gpointer user_data)
{
  fix_dark();
  ...
}
```
