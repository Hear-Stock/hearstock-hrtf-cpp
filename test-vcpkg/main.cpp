#include <curl/curl.h> // This will be imported from vcpkg.
#include <iostream>

int main(void) {
    CURL* curl;
    CURLcode res;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Check if curl was initialized correctly
    if (!curl) {
        std::cerr << "curl_easy_init() failed" << std::endl;
        curl_global_cleanup();
        return 1;
    }

    // Set the URL to send the request to
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");

    // Perform the request
    res = curl_easy_perform(curl);
    std::cout << std::endl;

    // Check if the request was successful
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << "HTTPS request succeeded" << std::endl;
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}