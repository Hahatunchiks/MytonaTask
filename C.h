#ifndef MYTONATASKS_C_H
#define MYTONATASKS_C_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>


size_t defineProtocol(const std::string &url, std::string &protocol) {
    size_t pos = url.find("://");
    if (pos != std::string::npos) {
        protocol = url.substr(0, pos);
    } else {
        pos = 0;
    }
    return pos;
}

size_t defineHost(const std::string &url, const size_t &startPosition, std::string &host, const size_t &offset) {
    size_t nextPos = startPosition != 0 ? url.find(':', startPosition + offset) : url.find(':');
    if (nextPos != std::string::npos) {
        host = startPosition != 0 ? url.substr(startPosition + offset, nextPos - startPosition - offset) : url.substr(startPosition, nextPos);
        return nextPos;
    } else {
        nextPos = startPosition != 0 ? url.find('/', startPosition + offset) : url.find('/');
        if (nextPos != std::string::npos) {
            host = startPosition != 0 ? url.substr(startPosition + offset, nextPos - startPosition - offset) : url.substr(startPosition, nextPos);
            return nextPos;
        } else {
            host = startPosition != 0 ? url.substr(startPosition + offset, url.size()  - offset) : url.substr(startPosition, url.size());
            return url.size() - 1;
        }
    }
}

size_t definePort(const std::string &url, const size_t &startPos, std::string &port) {
    size_t nextPos = url.find(':', startPos);
    if(nextPos != std::string::npos) {
        size_t pageStart = url.find('/', nextPos);
        if(pageStart != std::string::npos) {
            port = url.substr(nextPos + 1, pageStart - 1 - nextPos);
            return pageStart;
        } else {
            port = url.substr(nextPos + 1, url.size() - 1 - nextPos);
            return url.size()  - 1;
        }
    } else {
        return startPos;
    }
}

void definePage(const std::string &url, const size_t &startPos, std::string &page) {
    if(startPos < url.size() - 1) {
        page = url.substr(startPos, url.size() - 1);
    }
}

void solveThirdTask() {
    std::vector<std::string> urls;
    std::string defaultProtocol = "http";
    std::string host;
    std::string defaultPort = "80";
    std::string defaultPage = "/";
    size_t offset = 3;
    urls.emplace_back("http://mytona.com/index.html");
    urls.emplace_back("https://mytona.com:8080/");
    urls.emplace_back("mytona.com");
    urls.emplace_back("mytona.com:8080");
    urls.emplace_back("mytona.com/index.html");
    urls.emplace_back("file://mytona.com/");
    urls.emplace_back("http://mySite.ru:1234/login.php");
    urls.emplace_back("http://mySite.com:1234/login/account.php");
    //Protocol: http Host: mytona.com Port: 80 Page: /index.html

    for (const auto &i : urls) {
        size_t hostPosition = defineProtocol(i, defaultProtocol);
        size_t PortPosition = defineHost(i, hostPosition, host, offset);
        size_t PagePosition = definePort(i, PortPosition, defaultPort);
        definePage(i, PagePosition, defaultPage);

        std::cout << "Protocol: " + defaultProtocol + " Host: " << host;
        std::cout << " Port: " + defaultPort << " Page: " << defaultPage;
        std::cout << '\n';

        defaultProtocol = "http";
        host = "";
        defaultPort = "80";
        defaultPage = "/";
    }
}
#endif //MYTONATASKS_C_H
