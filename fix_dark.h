#include <gtk/gtk.h>

void
fix_dark()
{
	gboolean dark = FALSE;

	// First attempt: use GSettings for the color-scheme
	GSettings *gs = g_settings_new("org.gnome.desktop.interface");
	if (gs) {
		gchar *color_scheme = g_settings_get_string(gs, "color-scheme");
		if (color_scheme) {
			if (g_strcmp0(color_scheme, "prefer-dark") == 0) {
				dark = TRUE;
			}
			g_free(color_scheme);
		}
		g_object_unref(gs);
	}

	// Fallback: if GSettings didn’t indicate dark mode, check the theme name
	if (!dark) {
		GtkSettings *gtk_settings = gtk_settings_get_default();
		if (gtk_settings) {
			gchar *theme_name = NULL;
			g_object_get(gtk_settings, "gtk-theme-name", &theme_name, NULL);
			if (theme_name) {
				// A simple fallback: if the theme name contains "-dark" or "Dark",
				// we assume a dark theme.
				if (strstr(theme_name, "-dark") || strstr(theme_name, "Dark"))
					dark = TRUE;
				g_free(theme_name);
			}
		}
	}

	GtkSettings *sett = gtk_settings_get_default();
	if (dark) {
		g_object_set(sett, "gtk-application-prefer-dark-theme", TRUE, NULL);
	}
	//return dark;
}
