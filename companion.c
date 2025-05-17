#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define IDLE_THRESHOLD 300 // 5 minutes in seconds

const char* messages[] = {
    "Rest your eyes!",
    "Do a quick stretch!",
    "Shake off the stiffness!",
    "Take a quick walk!",
    "Time for a mini-break!"
};

int get_idle_time() {
    LASTINPUTINFO lii;
    lii.cbSize = sizeof(LASTINPUTINFO);
    GetLastInputInfo(&lii);
    DWORD tickCount = GetTickCount();
    return (tickCount - lii.dwTime) / 1000;
}

void log_activity(const char *status, const char *message) {
    FILE *log = fopen("companion.log", "a");
    if (log == NULL) {
        perror("Unable to open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local);

    fprintf(log, "[%s] STATUS: %s. MESSAGE: %s\n", time_str, status, message);
    fclose(log);
}

int main() {
    int message_counter = 0;
    time_t last_check_time = time(NULL);

    printf("Hello, I am your Linux Companion!\n");

    while (1) {
        int idle_time = get_idle_time();
        time_t current_time = time(NULL);

        if (current_time - last_check_time >= 60) { // Check every minute
            last_check_time = current_time;

            if (idle_time >= IDLE_THRESHOLD) {
                printf("%s (Idle %d sec)\n", messages[message_counter], IDLE_THRESHOLD);
                log_activity("IDLE", messages[message_counter]);

                message_counter = (message_counter + 1) % (sizeof(messages) / sizeof(messages[0]));
            }
        }

        Sleep(1000); // 1 second pause
    }

    return 0;
}
