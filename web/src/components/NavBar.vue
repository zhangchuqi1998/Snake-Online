<template>
<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <div class="container">
    <router-link class="navbar-brand" :to="{name: 'home'}">King of Bots</router-link>
    <div class="collapse navbar-collapse" id="navbarText">
      <ul class="navbar-nav me-auto mb-2 mb-lg-0">
        <li class="nav-item">
          <router-link class="nav-link" :to="{name: 'pk_index'}">Battle</router-link>
        </li>
        <li class="nav-item">
           <router-link class="nav-link" :to="{name: 'record_index'}">Record</router-link>
        </li>
        <li class="nav-item">
           <router-link class="nav-link" :to="{name: 'leadingboard_index'}">LeadingBoard</router-link>
        </li>
      </ul>
      <ul class="navbar-nav">
         <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdownMenuLink" role="button" data-bs-toggle="dropdown" aria-expanded="false">
            Aaron Zhang
          </a>
          <ul class="dropdown-menu" aria-labelledby="navbarDropdownMenuLink">
            <li><router-link class="dropdown-item" :to="{name: 'user_bot_index'}">My Bot</router-link></li>
             
            <li><a class="dropdown-item" href="#">Exit</a></li>
          </ul>
        </li>
      </ul>
      
    </div>
  </div>
</nav>
</template>


<script>

</script>

<style scoped>

</style>