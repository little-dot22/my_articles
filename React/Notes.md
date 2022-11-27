# React
## 1 JSX
### 1.1 概念
JSX是JavaScript(HTML)的缩写，用于在JS代码中书写HTML结构。
- 与HTML语法类似
- 充分利用JS自身的可编程能力创建HTML结构
### 1.2 JSX表达式
{ JS 表达式 }

    const userName = 'Andy'
    const getAge = () => {
      return 18
    }
    const flag = true
    
    function App () {
      return (
        <div className="App">
          {userName}
          {getAge()}
          {flag ? 'yes' : 'no'}
        </div>
      )
    }
    
    export default App
- **注意：**
  - 不能写语句，如：if
### 1.3 JSX列表渲染
**map()**
songs.map( item => \<li key={song.id}> {item.name} \</li> )

    const songs = [
      { id: 1, name: '痴心绝对' },
      { id: 2, name: '像我这样的人' },
      { id: 3, name: '南山南' }
    ]
    
    function App () {
      return (
        <div className="App">
          <ul>
            {songs.map(song=><li key={song.id}>{song.name}</li>)}
          </ul>
        </div>
      )
    }
    
    export default App
### 1.3 JSX条件渲染
    const flag = true
    function App() {
      return (
        <div className="App">
          {flag ? 'react真有趣' : 'vue真有趣'}
          {flag ? <span>this is span</span> : null}
        </div>
      )
    }
    export default App
### 1.4 JSX样式控制
- 行内样式1

      function App() {
        return (
          <div className="App">
            <span style={{color:'red'}}>span</span>
          </div>
        )
      }
      export default App
- 行内样式2

        const style = {
          color: 'green'
        }
        function App () {
          return (
            <div className="App">
              <span style={style}>span</span>
            </div>
          )
        }
        export default App
- 类名样式

    **App.js:**
    
        import './App.css';
        
        function App () {
          return (
            <div className="App">
              <span className='active'>类名样式</span>
            </div>
          )
        }
        export default App
    **App.css:**
    
        .active {
          color: blue;
        }
### 1.5 注意事项
1. JSX有且只有一个根节点，要避免语法错误，且真的不渲染一个节点，需要用到**幽灵节点，<></>**
2. 标签闭合
3. JSX语法贴近JS
4. JSX支持多行（换行），小括号可以突出语义，防止bug出现
## 2 组件
### 2.1 组件概念
一个个小功能独立起来
### 2.2 函数组件
使用 JS 的函数（或箭头函数）创建的组件，就叫做函数组件。

    // 组件创建
    function Hello(){
      return <div>hello</div>
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <Hello></Hello>
        </div>
      )
    }
    export default App
**注意：**
   - 组件名称首字母必须大写
   - 函数组件必须有返回值
   - 组件像HTML标签一样可以被渲染到页面中
   - 使用函数名称作为组件标签名称，成对出现或自闭合
### 2.3 类组件

    import React from "react"
    
    // 组件创建
    class HelloComponent extends React.Component{
      render(){
        return <div>this is Class Component</div>
      }
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <HelloComponent></HelloComponent>
        </div>
      )
    }
    export default App
**注意：**
   - 类名称首字母也要大写
   - 类组件应该继承React.Component父类，从而使用其方法和属性
   - 类组件必须提供render方法，要有返回值
### 2.4 事件绑定
on + 事件名称 = { 事件处理程序 } ，
比如：<div onClick={ onClick }>\</div>

    import React from "react"
    
    // 组件创建
    function Hello () {
      const clickHandler = () => {
        console.log('函数组件中的事件被触发了')
      }
      return <div onClick={clickHandler}>hello</div>
    }
    
    class HelloComponent extends React.Component {
      clickHandler = () => {
        console.log('类组件中的事件被触发了')
      }
      render () {
        return <div onClick={this.clickHandler}>This is a Class Component</div>
      }
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <Hello></Hello>
          <HelloComponent></HelloComponent>
        </div>
      )
    }
    export default App
**注意：**
   - 事件名称遵循驼峰命名法
### 2.5 事件对象e
同JS
### 2.6 事件绑定传递额外参数

    // 组件创建
    function Hello () {
      const clickHandler = (msg) => {
        console.log(msg)
      }
      return <div onClick={()=>clickHandler('test')}>hello</div>
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <Hello></Hello>
        </div>
      )
    }
    export default App
**注意：**
   - 利用箭头函数传参
### 2.7 组件状态的定义使用
在React hook出来之前，函数式组件是没有自己的状态的，所以我们统一通过类组件来讲解

    import React from "react"
    
    class TestComponent extends React.Component {
      state = {
        name: 'cp teacher'
      }
    
      changeName = () => {
        this.setState(
          { name: 'cp' }
        )
      }
    
      render () {
        return (
          <div>
            this is TestComponent
            当前name为: {this.state.name}
            <button onClick={this.changeName}>修改name</button>
          </div>
        )
      }
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <TestComponent></TestComponent>
        </div>
      )
    }
    export default App
### 2.8 总结
1. 编写组件实际上就是编写原生JS类或函数
2. 定义状态必须通过state实例属性的方法，提供一个对象，名称是固定的（state）
3. 修改state中的任何属性，都不可以直接赋值，都必须通过setState方法，这个方法由继承得到
4. 这里的this很容易出现指向错误的问题，上面的写法是最规范的，没有this指向问题
### 2.9 小案例

    import React from "react"
    
    class Counter extends React.Component {
      state = {
        count: 0
      }
    
      changeCount = () => {
        this.setState(
          {count: this.state.count+1}
        )
      }
    
      clearCount = () => {
        this.setState(
          {count: 0}
        )
      }
    
      render () {
        return (
          <div>
            <button onClick={this.changeCount}>{this.state.count} click</button>
            <button onClick={this.clearCount}>clear</button>
          </div>
        )
      }
    }
    
    // 组件渲染
    function App () {
      return (
        <div className="App">
          <Counter></Counter>
        </div>
      )
    }
    export default App
### 2.10 this的指向问题
