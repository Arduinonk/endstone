

# Class endstone::MapRenderer



[**ClassList**](annotated.md) **>** [**endstone**](namespaceendstone.md) **>** [**MapRenderer**](classendstone_1_1MapRenderer.md)



_Represents a renderer for a map._ 

* `#include <endstone/map/map_renderer.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**void**](classendstone_1_1Vector.md) | [**initialize**](#function-initialize) ([**MapView**](classendstone_1_1MapView.md) & map) <br>_Initialize this_ [_**MapRenderer**_](classendstone_1_1MapRenderer.md) _for the given map._ |
|  [**bool**](classendstone_1_1Vector.md) | [**isContextual**](#function-iscontextual) () const<br>_Get whether the renderer is contextual, i.e. has different canvases for different players._  |
| virtual [**void**](classendstone_1_1Vector.md) | [**render**](#function-render) ([**MapView**](classendstone_1_1MapView.md) & map, [**MapCanvas**](classendstone_1_1MapCanvas.md) & canvas, [**Player**](classendstone_1_1Player.md) & player) = 0<br>_Render to the given map._  |
| virtual  | [**~MapRenderer**](#function-maprenderer) () = default<br> |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|   | [**MapRenderer**](#function-maprenderer-12) () <br>_Initialize the map renderer base to be non-contextual._  |
|   | [**MapRenderer**](#function-maprenderer-22) ([**bool**](classendstone_1_1Vector.md) contextual) <br>_Initialize the map renderer base with the given contextual status._  |




## Public Functions Documentation




### function initialize 

_Initialize this_ [_**MapRenderer**_](classendstone_1_1MapRenderer.md) _for the given map._
```C++
virtual void endstone::MapRenderer::initialize (
    MapView & map
) 
```





**Parameters:**


* `map` The [**MapView**](classendstone_1_1MapView.md) being initialized. 




        

<hr>



### function isContextual 

_Get whether the renderer is contextual, i.e. has different canvases for different players._ 
```C++
bool endstone::MapRenderer::isContextual () const
```





**Returns:**

true if contextual, false otherwise. 





        

<hr>



### function render 

_Render to the given map._ 
```C++
virtual void endstone::MapRenderer::render (
    MapView & map,
    MapCanvas & canvas,
    Player & player
) = 0
```





**Parameters:**


* `map` The [**MapView**](classendstone_1_1MapView.md) being rendered to. 
* `canvas` The canvas to use for rendering. 
* `player` The player who triggered the rendering. 




        

<hr>



### function ~MapRenderer 

```C++
virtual endstone::MapRenderer::~MapRenderer () = default
```




<hr>
## Protected Functions Documentation




### function MapRenderer [1/2]

_Initialize the map renderer base to be non-contextual._ 
```C++
endstone::MapRenderer::MapRenderer () 
```




<hr>



### function MapRenderer [2/2]

_Initialize the map renderer base with the given contextual status._ 
```C++
explicit endstone::MapRenderer::MapRenderer (
    bool contextual
) 
```





**Parameters:**


* `contextual` Whether the renderer is contextual. 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `include/endstone/map/map_renderer.h`

