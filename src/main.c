#include <string.h>
#include <gtk/gtk.h>
#include "todo.h"

static GtkBuilder *builder;
static GObject *window;
static GObject *todo_button;
static GtkEntry *todo_entry;

GError *error = NULL;

static void on_add_todo_button(GtkButton *button, GtkEntry *entry) {
	const gchar *gtk_text = gtk_entry_get_text(entry);
	char *input_string = g_strdup(gtk_text);
	add_todo(input_string);
	gtk_entry_set_text(entry, "");
	free(input_string);
}

static void init_button() {
	todo_button = gtk_builder_get_object(builder, "add_todo_button");
    g_signal_connect(todo_button, "clicked", G_CALLBACK(on_add_todo_button), todo_entry);
}

static void init_todo_entry() {
	todo_entry = GTK_ENTRY(gtk_builder_get_object(builder, "todo_entry"));
}

static void init_window() {
	window = gtk_builder_get_object(builder, "window");
    g_signal_connect(GTK_WIDGET(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

}

static void init_builder() {
	builder = gtk_builder_new();
    if (!gtk_builder_add_from_file(builder, "src/builder.xml", &error)) {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }
}

static void first_render() {
	init_builder();
	init_window();
	init_todo_entry();
	init_button();    
	gtk_widget_show_all(GTK_WIDGET(window));
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	first_render();
	gtk_main();
	return 0;
}
