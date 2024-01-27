#include <gtk/gtk.h>
#include <stdio.h>

// Globale Variable
int counter = 0;

void print_hello() {
 printf("Hello GUI\n");
}

void count(GtkWidget *button, gpointer *countLabel) {
    counter++;
    char text[20];
    snprintf(text, sizeof(text), "%d", counter);
    gtk_label_set_text(GTK_LABEL(countLabel), text);
}

void activate(GtkApplication *app, gpointer user_data) {
    // Fenster Config
    GtkWidget *window = gtk_application_window_new(app); // erstellt ein neues voll funktionsfähiges Fenster
    gtk_window_set_title(GTK_WINDOW(window), "Übung 9: GUI"); // Ändert den Namen des Fensters.
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200); // Setzt die Anfangsgröße des Fensters.

    // Grid erstellen
    GtkWidget *grid = gtk_grid_new(); // Erstellt ein Element, dass ein Gridsystem enthält, um mehrere Elemente strukturiert anzuordnen.
    // Das Gridsystem besteht aus Zellen, dessen Start in der Ecke links oben ist.
    gtk_window_set_child(GTK_WINDOW(window), grid); // Fügt das Gridsystem als Kindelement des Fensters hinzu.

    // Zaehler Label
    GtkWidget *countLabel = gtk_label_new("0");
    gtk_grid_attach(GTK_GRID (grid), countLabel, 0, 0, 1, 1);

    // Button1 Config
    GtkWidget *button1 = gtk_button_new_with_label("Button 0");
    g_signal_connect(button1, "clicked", G_CALLBACK(count), countLabel);
    gtk_grid_attach(GTK_GRID (grid), button1, 0, 1, 1, 1); // Fügt den Button in der Gridzelle (0, 0) hinzu und soll nur eine Gridzelle ausfüllen.

    // Button2 Config
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    g_signal_connect(button2, "clicked", G_CALLBACK(count), countLabel);
    gtk_grid_attach(GTK_GRID (grid), button2, 1, 1, 1, 1); // Fügt den Button in der Gridzelle (1, 0) hinzu und soll nur eine Gridzelle ausfüllen.


    // Quit Button Config
    GtkWidget *quitButton = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped (quitButton, "clicked", G_CALLBACK(gtk_window_destroy), window); // gtk_window_destroy sendet ein Signal an das Fenster, dass es geschlossen werden soll.
    gtk_grid_attach(GTK_GRID (grid), quitButton, 0, 2, 2, 1); // Fügt den Button in der Gridzelle (0, 1)

    // Fenster final anzeigen
    gtk_window_present(GTK_WINDOW(window)); // Übergabe des Fensters an die Anzeige
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("de.hwr_berlin.uebung9_gui",G_APPLICATION_DEFAULT_FLAGS); // Initialisiert eine neue GTK Applikation.
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL); // Übergibt eine Funktion, die aufgerufen werden kann, um ein neues Fenster zu bauen.
    int status = g_application_run(G_APPLICATION(app), argc, argv); // Führt die Applikation -> im Endeffekt die hinterlegte Funktion activate().
    g_object_unref(app); // Gibt alle benötigten Ressourcen wieder frei. Ähnlich zu free() und fclose().
    return status;
}
