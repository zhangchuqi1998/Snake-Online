<template>
  <div id="nav">
    Bot: {{bot_name}}
  </div>
  <div>
    Bot a: {{bot_rating}}
  </div>
  <router-view/>
</template>

<script>

import $ from 'jquery';
import { ref } from 'vue';

export default{
  name: "app",
  setup: () => {
    let bot_name = ref("");
    let bot_rating = ref("");

    $.ajax({
      url: "http://127.0.0.1:3000/pk/getbotinfo/",
      type: "get",
      success: resp => {
        bot_name.value = resp[0];
        bot_rating.value = resp[1];
      }
    })

    return {
      bot_name,
      bot_rating
    }
  }
}
</script>

<style>

</style>
