

# Class endstone::PlayerTeleportEvent



[**ClassList**](annotated.md) **>** [**endstone**](namespaceendstone.md) **>** [**PlayerTeleportEvent**](classendstone_1_1PlayerTeleportEvent.md)



_Called when a player is teleported from one location to another._ 

* `#include <endstone/event/player/player_teleport_event.h>`



Inherits the following classes: [endstone::PlayerMoveEvent](classendstone_1_1PlayerMoveEvent.md)
































## Public Attributes inherited from endstone::PlayerMoveEvent

See [endstone::PlayerMoveEvent](classendstone_1_1PlayerMoveEvent.md)

| Type | Name |
| ---: | :--- |
|  [**Location**](classendstone_1_1Location.md) | [**from\_**](classendstone_1_1PlayerMoveEvent.md#variable-from_)  <br> |
|  [**Location**](classendstone_1_1Location.md) | [**to\_**](classendstone_1_1PlayerMoveEvent.md#variable-to_)  <br> |






























































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ENDSTONE\_EVENT**](#function-endstone_event) ([**PlayerTeleportEvent**](classendstone_1_1PlayerTeleportEvent.md)) <br> |
|   | [**PlayerMoveEvent**](#function-playermoveevent) ([**Player**](classendstone_1_1Player.md) & player, [**Location**](classendstone_1_1Location.md) from, [**Location**](classendstone_1_1Location.md) to) <br> |


## Public Functions inherited from endstone::PlayerMoveEvent

See [endstone::PlayerMoveEvent](classendstone_1_1PlayerMoveEvent.md)

| Type | Name |
| ---: | :--- |
|   | [**ENDSTONE\_EVENT**](classendstone_1_1PlayerMoveEvent.md#function-endstone_event) ([**PlayerMoveEvent**](classendstone_1_1PlayerMoveEvent.md)) <br> |
|   | [**PlayerMoveEvent**](classendstone_1_1PlayerMoveEvent.md#function-playermoveevent) ([**Player**](classendstone_1_1Player.md) & player, [**Location**](classendstone_1_1Location.md) from, [**Location**](classendstone_1_1Location.md) to) <br> |
|  [**const**](classendstone_1_1Vector.md) [**Location**](classendstone_1_1Location.md) & | [**getFrom**](classendstone_1_1PlayerMoveEvent.md#function-getfrom) () const<br>_Gets the location this player moved from._  |
|  [**const**](classendstone_1_1Vector.md) [**Location**](classendstone_1_1Location.md) & | [**getTo**](classendstone_1_1PlayerMoveEvent.md#function-getto) () const<br>_Gets the location this player moved to._  |
|  Result&lt; [**void**](classendstone_1_1Vector.md) &gt; | [**setFrom**](classendstone_1_1PlayerMoveEvent.md#function-setfrom) ([**const**](classendstone_1_1Vector.md) [**Location**](classendstone_1_1Location.md) & from) <br>_Sets the location to mark as where the player moved from._  |
|  Result&lt; [**void**](classendstone_1_1Vector.md) &gt; | [**setTo**](classendstone_1_1PlayerMoveEvent.md#function-setto) ([**const**](classendstone_1_1Vector.md) [**Location**](classendstone_1_1Location.md) & to) <br>_Sets the location that this player will move to._  |


## Public Functions inherited from endstone::Cancellable

See [endstone::Cancellable](classendstone_1_1Cancellable.md)

| Type | Name |
| ---: | :--- |
| virtual [**void**](classendstone_1_1Vector.md) | [**cancel**](classendstone_1_1Cancellable.md#function-cancel) () <br>_Cancel this event. A cancelled event will not be executed in the server, but will still pass to other plugins._  |
| virtual [**bool**](classendstone_1_1Vector.md) | [**isCancelled**](classendstone_1_1Cancellable.md#function-iscancelled) () override const<br>_Gets the cancellation state of this event. A cancelled event will not be executed in the server, but will still pass to other plugins._  |
| virtual [**void**](classendstone_1_1Vector.md) | [**setCancelled**](classendstone_1_1Cancellable.md#function-setcancelled) ([**bool**](classendstone_1_1Vector.md) cancel) override<br>_Sets the cancellation state of this event. A cancelled event will not be executed in the server, but will still pass to other plugins._  |


## Public Functions inherited from endstone::ICancellable

See [endstone::ICancellable](classendstone_1_1ICancellable.md)

| Type | Name |
| ---: | :--- |
| virtual [**void**](classendstone_1_1Vector.md) | [**cancel**](classendstone_1_1ICancellable.md#function-cancel) () = 0<br> |
| virtual [**bool**](classendstone_1_1Vector.md) | [**isCancelled**](classendstone_1_1ICancellable.md#function-iscancelled) () const = 0<br> |
| virtual [**void**](classendstone_1_1Vector.md) | [**setCancelled**](classendstone_1_1ICancellable.md#function-setcancelled) ([**bool**](classendstone_1_1Vector.md) cancel) = 0<br> |
| virtual  | [**~ICancellable**](classendstone_1_1ICancellable.md#function-icancellable) () = default<br> |










































































































## Public Functions Documentation




### function ENDSTONE\_EVENT 

```C++
endstone::PlayerTeleportEvent::ENDSTONE_EVENT (
    PlayerTeleportEvent
) 
```




<hr>



### function PlayerMoveEvent 

```C++
inline explicit endstone::PlayerTeleportEvent::PlayerMoveEvent (
    Player & player,
    Location from,
    Location to
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `include/endstone/event/player/player_teleport_event.h`

