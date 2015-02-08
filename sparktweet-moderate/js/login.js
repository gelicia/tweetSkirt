var converter = new Showdown.converter();

var Login = React.createClass({
  handleSubmit: function(e) {
    alert("hello!");
  },
  render: function() {
    return (
      <div className="Login">
        <h1>Login</h1>
        <form className="login" onSubmit={this.handleSubmit}>
          <input type="text" value="gelicia" /> <br/>
          <input type="password" /> <br/>
          <input type="submit" value="Post" />
        </form>
      </div>
    );
  }
});

React.render(
  <Login/>,
  document.getElementById('content')
);