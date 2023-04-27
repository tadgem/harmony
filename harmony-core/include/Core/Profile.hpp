#pragma once

#include <string>
#include <vector>
#include <thread>
#include "ThirdParty/json.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"

/// Thank you cherno
/// https://gist.github.com/TheCherno/31f135eea6ee729ab5f26a6908eb3a5e
struct ProfileResult {
    std::string Name;
    long long Start, End;
    uint32_t ThreadID;
};

struct InstrumentationSession {
    std::string Name;
};

class Instrumentor {
private:
    InstrumentationSession *m_CurrentSession;
    int m_ProfileCount;
    std::map<std::string, ProfileResult> m_ProfileResults;
public:
    Instrumentor()
            : m_CurrentSession(nullptr), m_ProfileCount(0) {
    }

    void BeginSession(const std::string &name) {
        // m_OutputStream.open(filepath);
        WriteHeader();
        m_CurrentSession = new InstrumentationSession{name};
    }

    void EndSession() {
        // WriteFooter();
        // m_OutputStream.close();
        delete m_CurrentSession;
        m_CurrentSession = nullptr;
        m_ProfileCount = 0;
    }

    void WriteProfile(const ProfileResult &result) {
        /*if (m_ProfileCount++ > 0)
            m_OutputStream << ",";

        std::string name = result.Name;
        std::replace(name.begin(), name.end(), '"', '\'');

        m_OutputStream << "{";
        m_OutputStream << "\"cat\":\"function\",";
        m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
        m_OutputStream << "\"name\":\"" << name << "\",";
        m_OutputStream << "\"ph\":\"X\",";
        m_OutputStream << "\"pid\":0,";
        m_OutputStream << "\"tid\":" << result.ThreadID << ",";
        m_OutputStream << "\"ts\":" << result.Start;
        m_OutputStream << "}";

        m_OutputStream.flush();*/

        if (m_ProfileResults.find(result.Name) != m_ProfileResults.end()) {
            long dist = result.End - result.Start;
            long oldStart = m_ProfileResults[result.Name].Start;
            long oldEnd = m_ProfileResults[result.Name].End;
            m_ProfileResults[result.Name].Start = (oldStart + result.Start) / 2;
            m_ProfileResults[result.Name].End = (oldEnd + result.End) / 2;
        }
        m_ProfileResults.emplace(result.Name, result);
    }

    void WriteHeader() {
        /*m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
        m_OutputStream.flush();*/
    }

    void WriteFooter() {
        /*m_OutputStream << "]}";
        m_OutputStream.flush();*/
    }

    static Instrumentor &Get() {
        static Instrumentor instance;
        return instance;
    }

    static std::map<std::string, ProfileResult> &GetResults() {
        return Get().m_ProfileResults;
    }

    static void ClearResults() {
        Get().m_ProfileResults.clear();
    }
};

class InstrumentationTimer {
public:
    InstrumentationTimer(const char *name)
            : m_Name(name), m_Stopped(false) {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer() {
        if (!m_Stopped)
            Stop();
    }

    void Stop() {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().
                count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().
                count();

        uint32_t threadID = static_cast<uint32_t>(std::hash<std::thread::id>{}(std::this_thread::get_id()));
        Instrumentor::Get().WriteProfile({m_Name, start, end, threadID});

        m_Stopped = true;
    }

private:
    const char *m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    bool m_Stopped;
};

#if 1
#define HARMONY_PROFILE_BEGIN_SESSION(name, filepath) Instrumentor::Get().BeginSession(name);
#define HARMONY_PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name);
#define HARMONY_PROFILE_FUNCTION() HARMONY_PROFILE_SCOPE(__FUNCTION__)
#define HARMONY_PROFILE_END_SESSION() Instrumentor::Get().EndSession();
#else
#define HARMONY_PROFILE_BEGIN_SESSION(name, filepath)
#define HARMONY_PROFILE_FUNCTION()
#define HARMONY_PROFILE_SCOPE(name)
#define HARMONY_PROFILE_END_SESSION()
#endif


