#ifndef HARMONY_CORE_ALIAS_H
#define HARMONY_CORE_ALIAS_H

#include "STL/Algorithm.h"
#include "STL/Array.h"
#include "STL/FileSystem.h"
#include "STL/Functional.h"
#include "STL/HashMap.h"
#include "STL/IO.h"
#include "STL/Map.h"
#include "STL/Memory.h"
#include "STL/Optional.h"
#include "STL/Stack.h"
#include "STL/String.h"
#include "STL/Thread.h"
#include "STL/TypeTraits.h"
#include "STL/Util.h"
#include "STL/Vector.h"

#include "ThirdParty/json.hpp"

namespace harmony { 



    

    namespace Chrono = std::chrono;

    namespace ThisThread = std::this_thread;


    using Json = nlohmann::json;

}

#endif